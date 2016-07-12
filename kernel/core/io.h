#ifndef _CORE_IO_H_
#define _CORE_IO_H_
#include "../std/types.h"

u8 inportb(u16 port);

void outportb(u16 port, u8 data);
	
void reboot();

#endif