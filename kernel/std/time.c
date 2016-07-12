#include "time.h"

// get current time
void gettime(struct time* t)
{
	struct time data;

	// start the 'time queue'
	outportb(0x70, 0x95);
	
	// get year
	outportb(0x70, 9);
	data.year = inportb(0x71);
	t->year = data.year - (data.year/16) * 6;

	// get month
	outportb(0x70, 8);
	data.month = inportb(0x71);
	t->month = data.month - (data.month/16) * 6;

	// get day
	outportb(0x70, 7);
	data.day = inportb(0x71);
	t->day = data.day - (data.day/16) * 6;
	
	// get weekday
	outportb(0x70, 6);
	data.weekday = inportb(0x71);
	if (data.weekday < 6) t->weekday = data.weekday + 2;
	else t->weekday = data.weekday - 5;
	
	// get hours
	outportb(0x70, 4);
	data.hour = inportb(0x71);
	t->hour = data.hour - (data.hour/16) * 6;

	// get minutes
	outportb(0x70, 2);
	data.minute = inportb(0x71);
	t->minute = data.minute - (data.minute/16) * 6;	
	
	// get seconds
	outportb(0x70, 0);
	data.second = inportb(0x71);
	t->second = data.second - (data.second/16) * 6;
}