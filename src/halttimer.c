#include <config.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <stdint.h>
#include <sys/time.h>
#include <unistd.h>
#include <xosd.h>
#ifdef HAVE_LIRC
#include <lirc/lirc_client.h>
#endif


typedef struct options {
    char *execute;
    int decrement;
    int threshold;
    int max;
} options;
options opts;

typedef struct {
    char *font;
    char *color;
    xosd_align align;
    int vertical_offset;
    int horizontal_offset;
    int timeout;
} xosd_options;

xosd *osd = NULL;

struct timeval tv_last, tv_current;

long timevaldiff(struct timeval *from, struct timeval *to) {
    long msec;
    msec = (to->tv_sec - from->tv_sec) * 1000;
    msec += (to->tv_usec - from->tv_usec) / 1000;

    return msec;
}

void catch_alarm(int sig) {
    xosd_display(osd, 0, XOSD_string, "Shutdown initiated");
    sleep(2);
    system(opts.execute);
}

void catch_usr1(int sig) {
    unsigned int old = alarm(0);
    unsigned int new;

    gettimeofday(&tv_current, NULL);

    if (timevaldiff(&tv_last, &tv_current) < opts.threshold * 1000) {
        if (old == 0) {
            new = opts.max * 60;
        } else {
            new = ((old - 1) / (opts.decrement * 60)) * (opts.decrement * 60);
        }
    } else {
        new = old;
    }

    alarm(new);

    if (new == 0) {
        xosd_display(osd, 0, XOSD_string, "Off");
    } else {
        char msg[20];
        sprintf(msg, "%d", new / 60, 20);
        xosd_display(osd, 0, XOSD_string, msg);
    }

    gettimeofday(&tv_last, NULL);
}

int run() {
    #ifdef HAVE_LIRC
        char *code, *x, ret;
        static struct lirc_config *lirc_config = NULL;

        if (lirc_init("lirctimer", 1) == -1) {
            fprintf(stderr, "Could not initialize LIRC system.");
            exit(EXIT_FAILURE);
        }

        /* Use the default config file in ~/.lircrc */
        if (lirc_readconfig(NULL, &lirc_config, NULL) != 0) {
            exit(EXIT_FAILURE);
        }

        /* Wait for keypresses. */
        while (lirc_nextcode(&code) == 0) {
            if (code == NULL)
                continue;

            while ((ret = lirc_code2char(lirc_config, code, &x)) == 0 && x != NULL) {
                raise(SIGUSR1);
            }
            free(code);
            if (ret == -1)
                break;
        }

        lirc_freeconfig(lirc_config);
        lirc_deinit();
    #else
        while (1) {
            pause();
        }
    #endif

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    /* Default values. */
    xosd_options osd_opts = {
        .font = "-*-helvetica-*-r-normal--100-*-*-*-*-*-*-*",
        .color = "LawnGreen",
        .timeout = 2,
        .align = XOSD_right,
        .vertical_offset = 10,
        .horizontal_offset = 10
    };

    opts.execute = "dbus-send --system --print-reply "
                   "--dest='org.freedesktop.ConsoleKit'"
                   "/org/freedesktop/ConsoleKit/Manager"
                   "org.freedesktop.ConsoleKit.Manager.Stop";
    opts.decrement = 15;
    opts.max = 120;
    opts.threshold = osd_opts.timeout;

    static struct option long_options[] = {
        {"font", required_argument, 0, 'f'},
        {"color", required_argument, 0, 'c'},
        {"execute", required_argument, 0, 'e'},
        {"osd-timeout", required_argument, 0, 'o'},
        {"decrement", required_argument, 0, 'd'},
        {"max", required_argument, 0, 'm'},
        {"align", required_argument, 0, 'a'},
        {"y-offset", required_argument, 0, 'y'},
        {"x-offset", required_argument, 0, 'x'},
        {"help", no_argument, 0, 'h'},
        {NULL, no_argument, NULL, 0}
    };

    int option_index, c;

    while (1) {
        option_index = 0;
        c = getopt_long(argc, argv, "f:c:e:o:d:m:a:y:x:h",
                long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
            case 'f':
                osd_opts.font = optarg;
                break;
            case 'c':
                osd_opts.color = optarg;
                break;
            case 'o':
                osd_opts.timeout = atoi(optarg);
                opts.threshold = osd_opts.timeout;
                break;
            case 'y':
                osd_opts.vertical_offset = atoi(optarg);
                break;
            case 'x':
                osd_opts.horizontal_offset = atoi(optarg);
                break;
            case 'a':
                if (optarg[0] == 'l') {
                    osd_opts.align = XOSD_left;
                } else if (optarg[0] == 'r') {
                    osd_opts.align = XOSD_right;
                } else if (optarg[0] == 'c') {
                    osd_opts.align = XOSD_center;
                } else {
                    fprintf(stderr, "Invalid argument to --align [l|c|r].\n");
                    return 1;
                }
                break;
            case 'e':
                opts.execute = optarg;
                break;
            case 'd':
                opts.decrement = atoi(optarg);
                break;
            case 'm':
                opts.max = atoi(optarg);
                break;
            case 'h':
                printf("usage: lirctimer [-e command] ... [-c color] [-f font]\n\n");
                printf("please see the man page for more options.\n");
                return EXIT_SUCCESS;
            default:
                abort();
                break;
        }
    }

    osd = xosd_create(1);
    xosd_set_font(osd, osd_opts.font);
    xosd_set_colour(osd, osd_opts.color);
    xosd_set_timeout(osd, osd_opts.timeout);
    xosd_set_align(osd, osd_opts.align);
    xosd_set_vertical_offset(osd, osd_opts.vertical_offset);
    xosd_set_horizontal_offset(osd, osd_opts.horizontal_offset);
    xosd_set_shadow_offset(osd, 1);

    signal(SIGUSR1, catch_usr1);
    signal(SIGALRM, catch_alarm);
    int ret = run();

    xosd_destroy(osd);
    return ret;
}
