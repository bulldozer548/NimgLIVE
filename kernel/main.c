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
            console_write("\nSorry, the console buffer has reached its limit!\n");
            console_color(BLACK, LIGHT_GREEN);
        } else if (strcmp(read_buff, "help") == 0) {
            console_color(BLACK, WHITE);
            console_write("Commands: help, about, credits, clear, restart, todolist, exit\n");
            console_color(BLACK, LIGHT_GREEN);
		} else if (strcmp(read_buff, "about") == 0) {
            console_color(BLACK, WHITE);
            console_write("nimgOS Alpha\nCopyright (c) 2019 Njifra and contributors.\nType \"credits\" to see a list of all contributors.\n");
            console_color(BLACK, LIGHT_GREEN);
		} else if (strcmp(read_buff, "credits") == 0) {
            console_color(BLACK, WHITE);
            console_write("Thanks to the following people, who contributed to this project:"
			       "\n\tKrock (SmallJoker)"
			       "\n\tZumza (Zumza123)"
			       "\n\txerox123 (xerox123official)"
			       "\n\tF4ncy (xshotD)"
			       "\n\tbulldozer (bulldozer548)"
			       "\n\tNjifra (Njifra)\n");
            console_color(BLACK, LIGHT_GREEN);
		} else if (strcmp(read_buff, "todolist") == 0) {
            console_color(BLACK, WHITE);
            console_write("TODO list:\n\t- fix non-removable tab\n\t- add scrolling\n\t- add a command manager (no hardcoded commands, please)\n\t- re-implement system time display\n");
            console_color(BLACK, LIGHT_GREEN);
        } else if (strcmp(read_buff, "exit") == 0 || strcmp(read_buff, "quit") == 0) {
            console_color(BLACK, WHITE);
            console_write("exit: shutting down...");
            break;
        } else if (strcmp(read_buff, "clear") == 0)
            console_clear();
		else if (strcmp(read_buff, "reboot") == 0 || strcmp(read_buff, "restart") == 0) {
			reboot();
		}
        else {
            console_color(BLACK, WHITE);
            console_write(read_buff);
            console_write(": Invalid command\n");
            console_color(BLACK, LIGHT_GREEN);
        }
    }

}