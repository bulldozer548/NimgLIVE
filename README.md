# ![NimgOS](http://puu.sh/pZokD/0c4a83186e.jpg)
An operating system developed by people at the IRC server irc.rizon.net - channel #nimg_lobby

License: MIT (see file LICENSE for more details)

Code style guidelines: [Linux kernel coding style](https://www.kernel.org/doc/Documentation/CodingStyle)

# Fair Warning
This product is not finished or polished in any way. There is very few things to do in NimgOS, and that may change in the near future. However, you should consider this an 'Alpha.'

### Contributing
Developers are welcome to contribute to the kernel, the C code, whatever their strong point is.


# Building on Windows
Requirements
------------

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)
3. [Cygwin](https://www.cygwin.com/) or [MinGW](http://mingw.org/) [*1]
4. [A GCC cross-compiler toolchain for i586-elf](https://www.mediafire.com/folder/drj2bx193eiay/i586-elf-gcc) (only for Cygwin)

Build instructions
------------------

Add the downloaded programs to your PATH environment variable.
Create the directory `build` and run the script to build the project for the 32-bit QEMU environment.
QEMU will be started automatically when the build was successful.

[*1] Using MinGW requires a change in link.dl: Line 1 to `OUTPUT_FORMAT(pei-i386)`!


# Building on Linux
Requirements
------------

1. [Nasm](http://www.nasm.us)
2. [QEMU](http://wiki.qemu.org/Main_Page)

and the requirements that go with those.

Build instructions
------------------

Launch a shell (e.g. the GNOME Terminal, LXTerminal, xterm) and navigate to the NimgOS directory.

```bash

# Create build directory
mkdir build

# Make the b4_linux file executable.
chmod +x b4_linux

# Run the build script
./b4_linux

```

This will build NimgOS and run it in an 32 bit QEMU enviroment.

To easily build NimgOS, see [EASYINSTALL] (https://github.com/Njifra/NimgOS/blob/master/EASYINSTALL.md)
