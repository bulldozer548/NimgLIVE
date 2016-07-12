#ifndef _DISPLAY_DISPLAY_H_
#define _DISPLAY_DISPLAY_H_
#include "../std/types.h"

// display struct
struct display
{
	// cursor position
	u8 curX;
	u8 curY;
	
	// pointer to video memory
	string vidmem;
	
	// display information
	u8 width, height, depth;
	u32 vidmem_size;
};

struct display screen;

// clear all chars
void display_clear();

// initialize display
void display_init();

// set cursor position
void display_set_cursor(u8 x, u8 y);

// set cursor position
void display_update_cursor();

// write character to display
void write_char(char c);

// write string to display
void write_string(string str);

#endif