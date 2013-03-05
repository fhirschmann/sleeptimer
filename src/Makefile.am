bin_PROGRAMS = halttimer

halttimer_SOURCES = halttimer.c
halttimer_LDFLAGS = @XOSD_LDFLAGS@
if HAVE_LIRC
	halttimer_LDFLAGS += -llirc_client
endif
