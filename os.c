#include "kernel/display/display.h"
#include "kernel/drivers/ps2.h"
#include "kernel/core/io.h"
#include "kernel/std/stdio.h"
#include "kernel/std/time.h"
#include "kernel/unittest/unittest.h"

void print_time()
{
	struct time tm;
	gettime(&tm);
	
	output("%d.%d.%d, %d:%d:%d", tm.day, tm.month, tm.year, tm.hour, tm.minute, tm.second);
}

void kern_main()
{
	display_init();
	std_test();
	PS2_init();
	
	output("NimgLIVE started successfully on ");
	print_time();
	output("\nLive distribution created by bulldozer");
	output("\nGet the list of commands by using command help.\nEnter a command:\n");
	
	string cmd = 0;
	
	while (1)
	{
		output("> ");
		gets(cmd);
		
		str2lower(cmd);
		
		if (strcmp(cmd, "help") == 0)
			output("Commands: help - about - clear - time - restart - todolist");
		else if (strcmp(cmd, "about") == 0)
			output("NimgOS Alpha - Copyright (c) 2016 Njifra and contributors\nNimgLIVE created by bulldozer");
		else if (strcmp(cmd, "clear") == 0)
			display_clear();
		else if (strcmp(cmd, "restart") == 0)
			reboot();
		else if (strcmp(cmd, "todolist") == 0)
			output("TODO list:\n\t- fix unremovable CTRL+C\n\t- add scroll\n\t- add command manager (no hardcoding commands, please)");
		else if (strcmp(cmd, "time") == 0) {
			output("Current time: ");
			print_time();
		} else if (strcmp(cmd, "kock") == 0)
			output("dem kock");
		else
			write_string("Command not found.");
		
		output("\n");
		
		cmd = 0;
	}
}
