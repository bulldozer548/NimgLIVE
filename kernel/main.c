#include "sys/console.h"
#include "std/string.h"

char read_buff[100];

void kernel_run() {
    console_color(BLACK, LIGHT_GREEN);
    cursor_color(BLACK, LIGHT_RED);

    console_write("--------------------\n");
    console_write("|Welcome to nimgOS!|\n");
    console_write("--------------------\n\n");

    while (TRUE) {
        console_write("@Genie> ");
        console_read(read_buff, 99);
        if (strlen(read_buff) == 100) {
            console_color(BLACK, WHITE);
            console_write("\nSorry, the console buffer has reached its limit!\n\n");
            console_color(BLACK, LIGHT_GREEN);
        } else if (strcmp(read_buff, "help") == 0) {
            console_color(BLACK, WHITE);
            console_write("help: There is no help!\n\n");
            console_color(BLACK, LIGHT_GREEN);
        } else if (strcmp(read_buff, "exit") == 0 || strcmp(read_buff, "quit") == 0) {
            console_color(BLACK, WHITE);
            console_write("exit: shutting down...");
            break;
        } else if (strcmp(read_buff, "clear") == 0)
            console_clear();
        else {
            console_color(BLACK, WHITE);
            console_write("Command ");
            console_write(read_buff);
            console_write(" wasn't found on this system.\n\n");
            console_color(BLACK, LIGHT_GREEN);
        }
    }

}