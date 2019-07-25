#include "console.h"
#include "hardware.h"
#include "../drivers/keyboard.h"
#include "../std/string.h"

struct {

    // video memory buffer
    char* buffer;
    uint16 buffer_size;

    //console sizes
    uint8 width;
    uint8 height;

    // console color used both for foreground and background
    uint8 color;

} console;

struct {

    // cursor positions
    uint8 x;
    uint8 y;

    // cursor color
    uint8 color;

    // cursor visibility
    bool show;

} cursor;

void console_init() {

    // initializing the video buffer to its memory location
    console.buffer = (char *) 0xB8000;

    // initializing console sizes
    console.width = 80;
    console.height = 25;

    // the buffer is made of pairs of 2 bytes
    // the first byte represents the char and the second byte represents it's color
    console.buffer_size = console.width * console.height * 2;

    // initializing the writing color
    console_color(BLACK, LIGHT_GREY);

    // clearing the video buffer
    console_clear();

    // initializing cursor
    cursor_init();

}

void cursor_init() {

    // initializing cursor color
    cursor.color = console.color;

    // initializing visibility
    cursor.show = FALSE;

}

void console_color(enum vga_color bg, enum vga_color fg) {

    // assigning a color for future writings
    console.color = fg | bg << 4;

}

void cursor_color(enum vga_color bg, enum vga_color fg) {

    // assigning a color for the cursor
    cursor.color = fg | bg << 4;

}

void console_clear() {

    // reinitializing video memory buffer
    uint16 i = 0;
    while (i < console.buffer_size) {
        console.buffer[i++] = ' ';
        console.buffer[i++] = console.color;
    }

    // reinitializing cursor position
    cursor_move(0, 0);

}

void console_put_char(char c) {

    // casting the type of char
    // the char is a real diva...
    switch (c) {
        case '\n':
            // new line
            cursor.y++;
            cursor.x = 0;
            break;

        case '\t':
            // TODO change
            if (cursor.x + 4 < console.width - 1)
                cursor.x += 4;
            break;

        default: {
            // calculating buff point from positions
            uint16 loc = (cursor.y * console.width + cursor.x) * 2;

            // writing the char
            console.buffer[loc++] = c;
            console.buffer[loc] = console.color; //using the designated color
            cursor.x++;
        }
    }

    // recalibrating cursor position
    cursor_recalibrate();

}

void console_write(const char *str) {

    // determine string length
    size_t length = strlen(str);

    // writing string char by char
    for(size_t i = 0; i < length; i++)
        console_put_char(str[i]);

    // unknown bug
    cursor.x--;

}

char console_read_key() {

    // waiting for key press
    while (!(inportb(0x64) & 0x01)) ;

    // returning the char
    return keymap(inportb(0x60));

}

void backspace() {

    // check if backspace is valid
    if (cursor.x > 0) {
        cursor.x--;

        // calculating buff point from positions
        uint16 loc = (cursor.y * console.width + cursor.x) * 2;

        // erasing
        console.buffer[loc++] = ' ';
        console.buffer[loc] = cursor.color;
    } else if (cursor.y > 0) {
        cursor.x = console.width - 1;
        cursor.y--;
    }

    cursor_recalibrate();

}

size_t console_read(char *str, size_t l) {

    // initializing elements
    size_t length = 0; // char stack
    char c; // tmp char

    // showing the cursor
    cursor_show(TRUE);

    // looping until enter key is pressed
    // or the length exceeds our buffer
    while (length < l) {
        // reading a single char from console
        c = console_read_key();

        // checks if the char isn't NULL
        if (c) {
            if (c == '\b') {
                // backspace is triggered
                // checks if we have a char to delete from stack
                if (length > 0) {
                    backspace();
                    length--;
                }
                continue;
            }

            // printing the char to console
            console_put_char(c);

            // exits if the char we read is enter
            if (c == '\n') break;

            // adding the char to stack
            str[length++] = c;
        }
    }

    // hiding the cursor
    cursor_show(FALSE);

    // ending the string
    str[length] = NULL;

    // returning the string length
    return length;

}

void cursor_show(bool show) {

    // showing the cursor
    cursor.show = TRUE;

    if (!show) {
        // making a copy of original values
        uint8 x = cursor.x;
        uint8 y = cursor.y;

        // assigning values outside the screen
        cursor.x = console.width;
        cursor.y = console.height;

        // rendering the cursor outside the screen
        cursor_render();

        // setting back to the original values
        cursor.x = x;
        cursor.y = y;

        // hiding the cursor
        cursor.show = FALSE;

        // exiting
        return;
    }

    // rendering the cursor at the designated position
    cursor_render();

}

void cursor_move(uint8 x, uint8 y) {

    // updating cursor position values
    cursor.x = x;
    cursor.y = y;

    // updating cursor position
    cursor_recalibrate();

}

void cursor_recalibrate() {

    // checking if cursor is on the right edge
    if (cursor.x >= console.width) {
        cursor.x = cursor.x - console.width;
        cursor.y++;
    }

    // clearing if screen is full
    if (cursor.y >= console.height)
        console_clear();

    // rendering the cursor at its position
    cursor_render();

}

void cursor_render() {

    // rendering the cursor if needed
    if (cursor.show) {
        // calculating buff point from positions
        uint16 loc = cursor.y * console.width + cursor.x;;
        uint16 loc2 = loc * 2;

        // erasing and filling with cursor color
        console.buffer[loc2++] = ' ';
        console.buffer[loc2] = cursor.color;

        // out-porting the settings
        outportb(0x3D4, 14);
        outportb(0x3D5, loc >> 8);
        outportb(0x3D4, 15);
        outportb(0x3D5, loc);
    }

}