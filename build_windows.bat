@echo off

echo Compiling kernel.asm
nasm -f elf -o build/asm.o kernel.asm

echo Compiling the main kernel function
i586-elf-gcc -m32 -o build/os.o -c os.c -nostdlib -lgcc

echo Compiling core
i586-elf-gcc -m32 -o build/io.o -c kernel/core/io.c -nostdlib -lgcc

echo Compiling display
i586-elf-gcc -m32 -o build/display.o -c kernel/display/display.c -nostdlib -lgcc

echo Compiling drivers
i586-elf-gcc -m32 -o build/ps2.o -c kernel/drivers/ps2.c -nostdlib -lgcc

echo Compiling std
i586-elf-gcc -m32 -o build/string.o -c kernel/std/string.c -nostdlib -lgcc
i586-elf-gcc -m32 -o build/time.o -c kernel/std/time.c -nostdlib -lgcc
i586-elf-gcc -m32 -o build/unistd.o -c kernel/std/unistd.c -nostdlib -lgcc
i586-elf-gcc -m32 -o build/output.o -c kernel/std/output.c -nostdlib -lgcc
i586-elf-gcc -m32 -o build/array.o -c kernel/std/array.c -nostdlib -lgcc

echo "Compiling unittest"
gcc -m32 -o build/std_test.o -c kernel/unittest/std_test.c -nostdlib -nostdinc

echo Compiling object files into kernel.bin
i586-elf-ld -m elf_i386 -T link.ld -o kernel.bin build/asm.o build/os.o^
 build/io.o build/display.o build/ps2.o build/string.o build/time.o^
 build/unistd.o build/output.o build/array.o build/std_test.o

echo Running operating system
qemu-system-i386 -kernel kernel.bin

pause