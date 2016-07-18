#include "gdt.h"

// initialize GDT entry
void gdt_entry_init(u32 id, unsigned long base, unsigned long max, u8 ac, u8 gr)
{
	gdt_ent[id].base_low = base & 0x0000FFFF;
	gdt_ent[id].base_middle = base & 0x00FF0000;
	gdt_ent[id].base_high = base & 0xFF000000;
	
	gdt_ent[id].limit = max & 0x0000FFFF;
	gdt_ent[id].ac = ac;
	gdt_ent[id].gr |= (gr & 0xF0);
	
}

// initialize GDT
void gdt_init()
{
	// set up gdt_info
	gdt.limit = (sizeof(struct GDT_entry) * 3) - 1;
	gdt.base = (u32)&gdt_ent;
	
	// NULL
	gdt_entry_init(0, 0, 0, 0, 0);
	
	// code segment
	gdt_entry_init(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

	// data segment
	gdt_entry_init(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

	
	gdt_reload_sr();
}
