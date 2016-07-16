#ifndef _CORE_GDT_H_
#define _CORE_GDT_H_

#include "../std/types.h"

// GDT entry
struct GDT_entry
{
	u16 limit;
	u16 base_low;
	u8 base_middle;
	u8 ac;
	u8 gr;
	u8 base_high;
};

// GDT
struct GDT
{
	u16 limit; 
	u32 base;
};

// define GDT with 3 entries
struct GDT gdt;
struct GDT_entry gdt_ent[3];

// the following function will be declared in kernel.asm
// it reloads the new segment registers
extern void gdt_reload_sr();

// initialize GDT entry
void gdt_entry_init(u32 id, unsigned long base, unsigned long max, u8 ac, u8 gr);

// initialize GDT
void gdt_init();



#endif
