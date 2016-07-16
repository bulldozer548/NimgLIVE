#include "../std/string.h"
#include "../std/time.h"
#include "unittest.h"

#define assert(condition) if (!(condition)) write_string("Assertion failed: " #condition "\n")

void std_test()
{
	struct time timedata;
	char text1[] = "foo";
	char text2[] = "bar";


	// string.c
	assert(strlen("test") == 4);
	assert(strcmp(text1, "foo") == 0);
	assert(strcmp(text1, text2) == ('f' - 'b'));
	assert(char2upper('a') == 'A');
	assert(char2upper('B') == 'B');
	assert(char2lower('C') == 'c');
	assert(char2lower('c') == 'c');

	memcpy(&text2, &text1, 2);
	assert(strcmp(text2, "for") == 0);


	// time.c
	timedata.year = 0xBADBEEF;
	gettime(&timedata);
	assert(timedata.year != 0xBADBEEF);

}