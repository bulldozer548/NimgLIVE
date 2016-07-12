# NimgOS
An operating system developed by people at the irc.rizon.net IRC server - channel #nimg_lobby

# Building (on windows)
To build this operating system, you have to install Cygwin, Nasm and QEMU and add their seperate bin folder paths to the system PATH enviroment variable.

Once you have done that, run the "build_windows.bat" script and ta-da, you are done.

# Building (on linux)
Requirements:

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)

and the requirements that go with those.
Once you've installed those, you are ready to launch NimgOS.

Launch an shell (e.g. the GNOME Terminal, LXTerminal, xterm) and navigate to the NimgOS directory, then do

```bash
./build-linux

```

This will build NimgOS and run it in an 32 bit QEMU enviroment.
