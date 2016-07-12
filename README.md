# NimgOS
An operating system developed by people at the irc.rizon.net IRC server - channel #nimg_lobby

# Building (on windows)
Requirements:

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)
3. [Cygwin](https://www.cygwin.com/)

Once you've installed those, add them to the SYSTEM PATH enviroment variable.
After that, create a folder "build" and run the script.

This will build NimgOS and run it in an 32 bit QEMU enviroment.

# Building (on linux)
Requirements:

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)

and the requirements that go with those.
Once you've installed those, you are ready to launch NimgOS.

Create a folder "build".

Launch an shell (e.g. the GNOME Terminal, LXTerminal, xterm) and navigate to the NimgOS directory, then do

```bash
chmod +x build_linux
./build-linux

```

This will build NimgOS and run it in an 32 bit QEMU enviroment.
