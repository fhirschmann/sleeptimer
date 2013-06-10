# halttimer

Halttimer is a LIRC-aware timer with an on-screen-display that initiates
the shut down sequence after a preset amount of time. It can be controlled by a single
button on an infrared remote control (via LIRC) or by a single key on a
keyboard.

It resembles what was (is?) commonly found in modern __televisions__,
where it usually called a __sleep timer__.

Halttimer's dependencies are minimal and it can be run on any platform where
xosd and LIRC (optionally) are available. This makes halttimer an ideal candidate for
home theater PCs (HTPCs), because it is platform-agnostic, which allows
you to use it with any media center solution.

![halttimer](http://static.0x0b.de/misc/halttimer.png)

## Installation

Halttimer is written in C and needs the following packages on Debian:

    apt-get install libxosd-dev

If LIRC-support is required:

    apt-get install liblircclient-dev

It can then be built by executing:

    ./autogen.sh
    ./configure
    make
    make install

Release tarballs that don't require autotools to be installed can be
[obtained from this site](http://dl.0x0b.de/halttimer).

## Manual
    HALTTIMER(1)			 User Commands			  HALTTIMER(1)
    
    
    
    NAME
           halttimer - a simple single-button lirc-aware shut down timer
    
    SYNOPSIS
           halttimer [OPTION]...
    
    DESCRIPTION
           Waits  for  LIRC  events or SIGUSR1 and sets a timer that will initiate
           the shut down sequence (via 'sudo halt' by default) when  the  time  is
           up.  The  timer's  timeout  decreases with each keypress by a specified
           amount of time.
    
    OPTIONS
           -f, --font
    	      font of the OSD text
    
           -c, --color
    	      color of the OSD text
    
           -t, --timeout
    	      timeout of the OSD text in seconds
    
           -y, --y-offset
    	      veritical offset of the OSD text in pixels
    
           -x, --x-offset
    	      horizontal offset of the OSD text in pixels
    
           -a, --align
    	      alignment of the OSD text; one of {l,c,r}
    
           -n, --no-lirc
    	      disable lirc
    
           -e, --execute
    	      command to execute when the time is up
    
           -d, --decrement
    	      number of minutes to decrement the counter by
    
           -m, --max
    	      maximum time of the counter in minutes
    
           -g, --grace
    	      time granted to cancel a scheduled shutdown in seconds
    
    FILES
           ~/.lircrc
    	   File that can be used to instruct halttimer to wait for a specific
    	   button on a remote control.
    
    EXAMPLES
           Use a different shutdown command:
           halttimer -e "systemctl poweroff"
    
           Use a different font:
           halttimer -f "-*-arial-*-r-normal--100-*-*-*-*-*-*-*"
    
           Set the maximum timeout to 120min with decrements of 10min:
           halttimer -m 120 -d 10
    
    CONFIGURATION
           Command Configuration
           First, halttimer needs to be able to shut the system down.  This can be
           done  in  many different ways, but by default, halttimer executes 'sudo
           halt'. Therefore, the following line must be present in your /etc/sudo‐
           ers and can be added using visudo(8).
    
           YOU ALL=(ALL) NOPASSWD: /sbin/halt
    
           where YOU is your username.
    
           Second, halttimer can be configured to wait for a LIRC signal, an arbi‐
           trary command, or both.
    
           LIRC Configuration
           If LIRC is desired, append the following to your ~/.lircrc
    
    	   begin
    	       prog = halttimer
    	       button = YOUR_BUTTON
    	       config = sleep
    	       repeat = 1
    	   end
    
           And press YOUR_BUTTON on your remote control. The name of a button  can
           be obtained using irw(1).
    
           Keyboard Configuration
           You  can  control  halttimer by simply sending the SIGUSR1 signal: kill
           -USR1 `pidof halttimer`.  This command could be bound to a key on  your
           keyboard.
    
    AUTHORS
           halttimer was written by Fabian Hirschmann <fabian@hirschm.net>.
    
    SEE ALSO
           irw(1),visudo(8).
    
    
    
    halttimer 0.3.1 		  March 2013			  HALTTIMER(1)
