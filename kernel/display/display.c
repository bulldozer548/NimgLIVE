#include "display.h"
#include "../std/string.h"

// clear all chars
void display_clear()
{
	u32 i = 0;
	for (i; i < screen.vidmem_size; i++)
		screen.vidmem[i] = NULL;
	
	screen.curX = 0;
	screen.curY = 0;
}

// initialize display
void display_init()
{
	screen.vidmem = (string)0xB8000;
	
	screen.width = 80;
	screen.height = 25;
	screen.depth = 2;
	
	screen.vidmem_size = screen.width * screen.height * screen.depth;
	
	display_clear();
}

// set cursor position
void display_set_cursor(u8 x, u8 y)
{
	if (x >= screen.width)
		x = screen.width - 1;
	
	if (y >= screen.height)
		y = screen.height - 1;
	
	// calculate position
	u16 pos = x+y*screen.width;
	
	// send position
    outportb(0x3D4, 14);
	outportb(0x3D5, pos >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, pos);
	
	// update information
	screen.curX = x;
	screen.curY = y;
}

// set cursor position
void display_update_cursor()
{
	display_set_cursor(screen.curX, screen.curY);
}

// write character to display
void write_char(char c)
{
	if (!(screen.curX < screen.width && screen.curY < screen.height))
		return;
	
	switch (c)
	{
		// newline
		case '\n':
			screen.curX = 0;
			screen.curY++;
		break;
		
		// backspace was pressed
		case '\b':
			if (screen.curX > 0) {
				screen.curX--;
				u32 pos = (screen.curY * screen.width + screen.curX) * screen.depth;
				screen.vidmem[pos] = 0x00;
				screen.vidmem[pos+1] = 0x0F;
			}
			else {
				if (screen.curY >= 0) {
					screen.curX = screen.width - 1;
					screen.curY--;
				}
			}
		break;
		
		// tab was pressed
		case '\t':
			screen.curX+=4;
		break;
		
		default:{
			// calculate location
			u32 loc = (screen.curY * screen.width + screen.curX) * screen.depth;
			
			screen.vidmem[loc] = c;		// put a char
			screen.vidmem[loc+1] = 0x0F;	// set a color
			
			// update cursor position
			screen.curX++; 
			break;
		}
	}
	
	// we went over the end
	if (screen.curX >= screen.width) {
		screen.curX = screen.curX - screen.width;
		screen.curY++;
	}
	
	// we went over the end
	if (screen.curY >= screen.height)
		display_clear();
	
	display_update_cursor();
	
	// TODO: check if we have to scroll view up
}

// write string to display
void write_string(string str)
{
	size_t len = strlen(str);
	u32 i = 0; 
	for(i; i < len; i++)
	{
		write_char(str[i]);
	}
}
