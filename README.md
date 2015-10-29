# sleeptimer

[![Build Status](https://travis-ci.org/fhirschmann/sleeptimer.png?branch=master)](https://travis-ci.org/fhirschmann/sleeptimer)

Sleeptimer is a LIRC-aware timer with an on-screen-display (OSD) that initiates
the shut down sequence after a preset amount of time. It can be controlled by a single
button on an infrared remote control (via LIRC) or by a single key on a
keyboard.

It resembles what was (is?) commonly found in modern __televisions__,
where it usually called a __sleep timer__.

Sleeptimer's dependencies are minimal and it can be run on any platform where
xosd and LIRC (optionally) are available. 

![sleeptimer](http://static.0x0b.de/misc/sleeptimer.png)

## Installation

Sleeptimer is written in C and needs the following packages on Debian:

    apt-get install libxosd-dev

If LIRC-support is required:

    apt-get install liblircclient-dev

It can then be built by executing:

    ./autogen.sh
    ./configure
    make
    make install

Release tarballs that don't require autotools to be installed can be
[obtained from this site](http://dl.0x0b.de/sleeptimer).

## Usage

In the simplest case (i.e. no LIRC, systemd poweroff), you can just
start sleeptimer by executing

	sleeptimer

and bind the

	sleeptimer-action

command to a key of your choice.

## Manual
    SLEEPTIMER(1)			 User Commands			  SLEEPTIMER(1)
    
    
    
    NAME
           sleeptimer - a simple single-button lirc-aware shut down timer
    
    SYNOPSIS
           sleeptimer [OPTION]...
    
    DESCRIPTION
           Waits  for  LIRC	 events or SIGUSR1 and sets a timer that will initiate
           the shut down sequence (via 'systemctl poweroff' by default)  when  the
           time is up. The timer's timeout decreases with each keypress by a spec‐
           ified amount of time.
    
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
    
    CONFIGURATION
           Command Configuration
           First, sleeptimer needs to be able to shut the system down.
    
           On modern systems using systemd and polkit, this is possible by default
           using 'systemctl poweroff' and there is nothing more to configure.
    
           On  older  systems,  this  can  be  done in many different ways, but by
           default, sleeptimer executes 'sudo halt'. Therefore, the following  line
           must be present in your /etc/sudoers and can be added using visudo(8).
    
           YOU ALL=(ALL) NOPASSWD: /sbin/halt
    
           where YOU is your username.
    
           Second, sleeptimer can be configured to wait for a LIRC signal, an arbi‐
           trary command, or both.
    
           LIRC Configuration
           If LIRC is desired, append the following to your ~/.lircrc
    
    	   begin
    	       prog = sleeptimer
    	       button = YOUR_BUTTON
    	       config = sleep
    	       repeat = 1
    	   end
    
           And press YOUR_BUTTON on your remote control. The name of a button  can
           be obtained using irw(1).
    
           Keyboard Configuration
           You  can	 control  sleeptimer by simply sending the SIGUSR1 signal: kill
           -USR1 `pidof sleeptimer`.	 This command could be bound to a key on  your
           keyboard.
    
    AUTHORS
           sleeptimer was written by Fabian Hirschmann <fabian@hirschmann.email>.
    
    FILES
           ~/.lircrc
    	   File that can be used to instruct sleeptimer to wait for a specific
    	   button on a remote control.
    
    EXAMPLES
           Use a different shutdown command:
           sleeptimer -e "systemctl poweroff"
    
           Use a different font:
           sleeptimer -f "-misc-liberation sans-medium-r-normal--*-360-*-*-p-*-*-*"
    
           Set the maximum timeout to 120min with decrements of 10min:
           sleeptimer -m 120 -d 10
    
    SEE ALSO
           irw(1),visudo(8).
    
    
    
    sleeptimer 0.3.2			 October 2015			  SLEEPTIMER(1)
