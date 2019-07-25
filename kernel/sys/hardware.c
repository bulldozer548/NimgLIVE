#include "hardware.h"

uint8 inportb(uint16 port) {
    uint8 data;
    asm volatile ("inb %%dx,%%al":"=a" (data):"d" (port));
    return data;
}

void outportb(uint16 port, uint8 data) {
    asm volatile ("outb %%al,%%dx": :"d" (port), "a" (data));
}