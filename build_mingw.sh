#!/bin/bash
echo "NimgOS build script for Linux; (c) 2016 NimgOS developers."

echo "Compiling kernel"
nasm -f elf32 -o build/asm.o kernel_mingw.asm

echo "Compiling the main kernel function"
gcc -m32 -o build/os.o -c os.c -nostdlib -nostdinc

echo "Compiling core functions"
gcc -m32 -o build/io.o -c kernel/core/io.c -nostdlib -nostdinc

echo "Compiling display functions"
gcc -m32 -o build/display.o -c kernel/display/display.c -nostdlib -nostdinc

echo "Compiling drivers"
gcc -m32 -o build/ps2.o -c kernel/drivers/ps2.c -nostdlib -nostdinc

echo "Compiling std objects"
gcc -m32 -o build/string.o -c kernel/std/string.c -nostdlib -nostdinc
gcc -m32 -o build/time.o -c kernel/std/time.c -nostdlib -nostdinc
gcc -m32 -o build/unistd.o -c kernel/std/unistd.c -nostdlib -nostdinc
gcc -m32 -o build/output.o -c kernel/std/output.c -nostdlib -nostdinc
gcc -m32 -o build/array.o -c kernel/std/array.c -nostdlib -nostdinc

echo "Compiling object files into kernel.bin"
ld -T link.ld -o kernel.a build/*.o
objcopy -O elf32-i386 kernel.a kernel.bin

echo "Running operating system"
qemu-system-i386 -kernel kernel.bin
sed -n q </dev/tty
