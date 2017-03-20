#include "../std/types.h"

#ifndef NIMGOS_CONSOLE_H
#define NIMGOS_CONSOLE_H

enum vga_color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15,
};

void console_init();
void cursor_move(uint8 x, uint8 y);
void cursor_color(enum vga_color bg, enum vga_color fg);
void console_clear();
void console_put_char(char c);
void console_color(enum vga_color bg, enum vga_color fg);
void console_write(const char *str);
char console_read_key();
size_t console_read(char *str, uint32 l);

#endif //NIMGOS_CONSOLE_H

