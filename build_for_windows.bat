@echo off
setlocal ENABLEDELAYEDEXPANSION

echo (c) 2019 nimgOS Team
echo --------------------

echo Creating a folder for the build
md build

echo Compiling kernel.asm
nasm -f elf kernel\kernel.asm -o build\kernel.o

echo Compiling additional parts of the kernel
for /r %%k in (*.c) do i586-elf-gcc -m32 -c -std=gnu99 -nostdlib -lgcc %%k -o build\%%~nk.o

echo Linking object files into kernel binary
for %%o in (build\*.o) do set ol=!ol! %%o
i586-elf-ld -m elf_i386 -T kernel\link.ld -o build\kernel.bin!ol!

echo Running nimgOS...
qemu-system-i386 -kernel build\kernel.bin

pause