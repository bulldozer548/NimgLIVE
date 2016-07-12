#ifndef _STD_TIME_H_
#define _STD_TIME_H_

#include "types.h"

struct time
{
	u32 weekday;
	u32 year;
	u32 month;
	u32 day;
	u32 hour;
	u32 minute;
	u32 second;
};

// get current time
void gettime(struct time* t);

#endif