#include "hardware.h"

uint8 inportb(uint16 port) {
    uint8 data;
    asm volatile ("inb %%dx,%%al":"=a" (data):"d" (port));
    return data;
}

void outportb(uint16 port, uint8 data) {
    asm volatile ("outb %%al,%%dx": :"d" (port), "a" (data));
}

void reboot() {
    uint8 good = 0x02;
    while ((good & 0x02) != 0)
        good = inportb(0x64);
    outportb(0x64, 0xFE);
}