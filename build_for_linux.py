#!/usr/bin/env python
import os

print('(c) 2019 nimgOS Team')
print('--------------------\n')

# initalizing
obj_files = []

if not os.path.isdir('./build'):
    os.makedirs('./build')

nasm_cmd = 'nasm -f elf ./kernel/kernel.asm -o ./build/kernel.o'
gcc_cmd = 'gcc -m32 -c -std=gnu99 -nostdlib -lgcc {} -o ./build/{}'
ld_cmd = 'ld -m elf_i386 -T kernel/link.ld -o ./build/kernel.bin ./build/kernel.o ./build/{}'
qemu_cmd = 'qemu-system-i386 -kernel ./build/kernel.bin'

#compiling

os.system(nasm_cmd)

# searching for all cfiles recursively
for root, dirs, files in os.walk("./kernel"):
    for file in files:
        if file.endswith(".c"):
            obj_file = file[:-1] + 'o'
            obj_files.append(obj_file)
            cmd = gcc_cmd.format(os.path.join(root, file), obj_file)
            os.system(cmd)
            
cmd = ld_cmd.format(' ./build/'.join(obj_files))
os.system(cmd)

# check if it worked

if os.path.exists('./build/kernel.bin'):
    print('\nIt worked :)')
    os.system(qemu_cmd)
else:
    print('\nThere have been some errors...')
    print('You may join channel #nimg_lobby at irc.rizon.net for help. :)')
