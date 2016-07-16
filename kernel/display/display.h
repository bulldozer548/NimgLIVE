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
	
	// current color
	u8 color;
};

struct display screen;

// all colors
typedef enum
{
	Black,
	Blue,   
	Green,
	Cyan,
	Red,
	Magenta,
	Brown,
	LightGrey,
	DarkGrey,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightMagenta,
	LightBrown,
	White
} Color;

// set color
void display_set_color(Color fg, Color bg);

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