#include "ps2.h"
#include "../display/display.h"
#include "../std/string.h"

// keyboard layout
const char ps2_keys_1[58] = {
	'\0',	'\x1B',	'1',	'2',
	'3',	'4',	'5',	'6',
	'7',	'8',	'9',	'0',
	'-',	'=',	'\b',	'\t',
	'q',	'w',	'e',	'r',
	't',	'y',	'u',	'i',
	'o',	'p',	'[',	']',
	'\n',	'\0',	'a',	's',
	'd',	'f',	'g',	'h',
	'j',	'k',	'l',	';',
	'\'',	'`',	'\0',	'\\',
	'z',	'x',	'c',	'v',
	'b',	'n',	'm',	',',
	'.',	'/',	'\0',	'\0',
	'\0',	' '
};

// keyboard layout when shift key is down and key code is not in range between 'a' and 'z'
// or when caps lock is down and its in range of 'a' and 'z'
const char ps2_keys_2[58] = {
	'\0',	'\x1B',	'!',	'@',
	'#',	'$',	'%',	'^',
	'&',	'*',	'(',	')',
	'_',	'+',	'\b',	'\t',
	'Q',	'W',	'E',	'R',
	'T',	'Y',	'U',	'I',
	'O',	'P',	'{',	'}',
	'\n',	'\0',	'A',	'S',
	'D',	'F',	'G',	'H',
	'J',	'K',	'L',	':',
	'"',	'~',	'\0',	'|',
	'Z',	'X',	'C',	'V',
	'B',	'N',	'M',	'<',
	'>',	'?',	'\0',	'\0',
	'\0',	' '
};


void PS2_create()
{
	drv_ps2.left_shift = false;
	drv_ps2.right_shift = false;
	drv_ps2.caps_lock_toggle = false;
	drv_ps2.caps_lock = false;
	drv_ps2.left_ctrl = false;
	drv_ps2.altgr = false;


	u32 i = 0;
	for (; i < 4; i++)
		drv_ps2.mouse_packet[i] = NULL;

	drv_ps2.mouse_index = 0;
	drv_ps2.mouse_x = 0;
	drv_ps2.mouse_y = 0;
}

void PS2_wait_keypress()
{
	while (!(inportb(0x64) & 0x01));
}

void PS2_init()
{
	// create it
	PS2_create();
}

u8 PS2_handle_scancode(u8 scancode)
{	// Convert PS2 input to character or NULL
	switch (scancode) {
			/* SHIFT KEY */
	case 0x2A:
		drv_ps2.left_shift = true;
		break;
	case 0xAA:
		drv_ps2.left_shift = false;
		break;
	case 0x36:
		drv_ps2.right_shift = true;
		break;
	case 0xB6:
		drv_ps2.right_shift = false;
		break;
			/* CAPS LOCK KEY */
	case 0x3A:
		if (!drv_ps2.caps_lock)
			drv_ps2.caps_lock = true;

		drv_ps2.caps_lock_toggle = !drv_ps2.caps_lock;
		break;
	case 0xBA:
		if (drv_ps2.caps_lock && !drv_ps2.caps_lock_toggle)
			drv_ps2.caps_lock = false;
		break;
			/* CTRL KEY */
	case 0x1D:
		drv_ps2.left_ctrl = true;
		break;
	case 0x9D:
		drv_ps2.left_ctrl = false;
		break;
			/* ALTGR KEY */
	case 0xE0: {
		u8 keycode = inportb(0x60);

		if (keycode == 0x38)
			drv_ps2.altgr = true;
		else if (keycode == 0xB8)
			drv_ps2.altgr = false;
		else
			scancode = keycode;
		} break;
	case 0:
		// Do nothing
		break;
	}

	if (drv_ps2.left_ctrl) {
		if (scancode == 0x2E)
			write_string("^C");
		else if (scancode == 0x20)
			write_string("^D");
	}

	bool uppercase = drv_ps2.caps_lock != (drv_ps2.left_shift || drv_ps2.right_shift);

	if (scancode < 58)
		return PS2_to_char(scancode & 0x7F, uppercase, drv_ps2.left_shift || drv_ps2.right_shift);

	return NULL;
}

bool PS2_is_letter(u8 c)
{
	return (c >= 16 && c <= 25
			|| c >= 30 && c <= 38
			|| c >= 44 && c <= 50);
}

u8 PS2_to_char(u8 scancode, bool uppercase, bool shift)
{
	// which table will we use?
	bool firstTable = true;

	// we will use second key layout table
	if ((shift && !PS2_is_letter(scancode)) || (uppercase && PS2_is_letter(scancode)))
		firstTable = false;

	// return character
	if (firstTable)
		return ps2_keys_1[scancode];
	else
		return ps2_keys_2[scancode];
}

char getc(bool enable_backspace)
{
	PS2_wait_keypress();

	u8 code = PS2_handle_scancode(inportb(0x60));

	if (!enable_backspace && code == '\b')
		return false;

	if (code != 0)
		write_char(code);
	
	return code;
}

void gets(string str)
{
	str = 0;
	size_t i = 0;
	char buf = 0;

	while (true) {
		buf = getc(i > 0);
		if (buf != 0) {
			if (buf == '\n')
				break;
			else if (buf == '\b')
				i--; // reduce for 2 since we do i++ later
			else {
				str[i] = buf;
				i++;
			}
		}
	}

	str[i] = '\0';
}
