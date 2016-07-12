#ifndef _DRIVERS_PS2_H_
#define _DRIVERS_PS2_H_
#include "../std/types.h"

// PS2 driver struct
struct PS2
{
	// read and write on data register at 0x60
	// read status register at 0x64
	// write on command register at 0x64
	
	bool left_shift;		// is left shift down
	bool right_shift;		// is right shift down
	bool caps_lock;			// is caps lock on or off?
	bool caps_lock_toggle;	// caps lock toggle
	bool left_ctrl;			// is left ctrl down?
	bool altgr;				// is alt gr down?
	
	u8 mouse_packet[4];		// mouse packet
	size_t mouse_index;		// mouse packet index
	u32 mouse_x;			// mouse position x
	u32 mouse_y;			// mouse position y
};


// define PS2 driver
struct PS2 drv_ps2;

// setup PS2 driver
void PS2_create();

// wait for key press
void PS2_wait_keypress();

// initialize PS2 driver
void PS2_init();

// handle scancode
u8 PS2_handle_scancode(u8 scancode);

// is scancode a letter
bool PS2_is_letter(u8 c);

// convert scan code to real character
u8 PS2_to_char(u8 scancode, bool uppercase, bool shift);

// read character
char getc();

// read string
void gets(string str);

#endif