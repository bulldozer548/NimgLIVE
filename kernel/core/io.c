#include "io.h"

u8 inportb(u16 port)
{
	u8 ret;
	asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
	return ret;
}
void outportb(u16 port, u8 data)
{
	asm volatile ("outb %%al,%%dx": :"d" (port), "a" (data));
}

void reboot() {
    u8 good = 0x02;
    while ((good & 0x02) != 0)
        good = inportb(0x64);
    outportb(0x64, 0xFE);
}