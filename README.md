# ![NimgOS](http://puu.sh/pZokD/0c4a83186e.jpg)
An operating system developed by people at the irc.rizon.net IRC server - channel #nimg_lobby

# Building (on windows)
Requirements:

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)
3. [Cygwin](https://www.cygwin.com/) or MinGW [*1]
4. [A GCC cross-compiler toolchain for i586-elf](https://www.mediafire.com/folder/drj2bx193eiay/i586-elf-gcc) (only for Cygwin)

Once you've installed those, add them to the SYSTEM PATH environment variable.
After that, create a folder "build" and run the script.

This will build NimgOS and run it in an 32 bit QEMU environment.

[*1] With some changes in the build script (b4_linux) and the kernel.asm file it is possible to compile this project with MinGW aswell.

# Building (on linux)
Requirements:

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)

and the requirements that go with those.
Once you've installed those, you are ready to launch NimgOS.

Launch an shell (e.g. the GNOME Terminal, LXTerminal, xterm) and navigate to the NimgOS directory.

Create a folder named "build".

```bash
mkdir build

```
Make the b4_linux file executable.

```bash
chmod +x b4_linux
```
Run the b4_linux file.

```bash
./b4_linux

```

This will build NimgOS and run it in an 32 bit QEMU enviroment.
