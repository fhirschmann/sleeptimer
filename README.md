# halttimer

Halttimer is a LIRC-enabled timer with an on-screen-display that initiates
a shutdown after a preset amount of time. It can be controlled by a single
button on an infrared remote control (via LIRC) or by a single key on the
keyboard.

![halttimer](http://static.0x0b.de/misc/halttimer.png)

## Installation

Halttimer is written in C and needs the following packages on Debian:

    apt-get install libxosd-dev

If LIRC-support is required:

    apt-get install liblircclient-dev

It can then be built by executing:

    autoreconf --install
    ./configure
    make
    make install

## Manual

Please consult the manual page, [halttimer(1)](http://halttimer.0x0b.de/halttimer.html) for details.
