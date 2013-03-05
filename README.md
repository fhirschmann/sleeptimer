# halttimer

Halttimer is a LIRC-enabled timer with an on-screen-display that issues
a shutdown after a preset amount of time. It can be controlled by a single
button on an infrared remote control (via LIRC) or by a single key on the
keyboard.

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

## Configuration

Add the following to your `~/.lircrc` if LIRC is desired:

    begin
        prog = halttimer
        button = YOUR_BOTTON
        config = sleep
        repeat = 1
    end

If you with to bind Halttimer to a key on your keyboard, use
your window manager's means to bind the key of your choice to:

    kill -SIGUSR1 `pidof halttimer`

## Usage

Halttimer needs to be running in the background. This can be accomplished
by adding `halttimer &` to your startup configuration. Please consult
the manpage for a detailed overview of the options. You may be interested
in `-m` and `-d`, which set the maximum timeout and the time decrement in
minutes, respectively.

Once it is running, you can start pressing the button on your remote control
or keyboard.
