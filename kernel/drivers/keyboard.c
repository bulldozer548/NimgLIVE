#include "keyboard.h"

// standard american keyboard layout
const char keyboardlayout[58] = {
        NULL,   '\x1B',	'1',	'2',
        '3',	'4',	'5',	'6',
        '7',	'8',	'9',	'0',
        '-',	'=',	'\b',   '\t',
        'q',	'w',	'e',	'r',
        't',	'y',	'u',	'i',
        'o',	'p',	'[',	']',
        '\n',	NULL,	'a',	's',
        'd',	'f',	'g',	'h',
        'j',	'k',	'l',	';',
        '\'',	'`',    NULL,	'\\',
        'z',	'x',	'c',	'v',
        'b',	'n',	'm',	',',
        '.',	'/',	NULL,	NULL,
        NULL,	' '
};

// TODO more

char keymap(uint8 code) {

    if (code < 58 && keyboardlayout[code & 0x7F])
        return keyboardlayout[code & 0x7F];
    return NULL;

}