/**********************************************************************
 * Copyright (C) Jaewon Choi <jaewon.james.choi@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 *********************************************************************/
#include "commands.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static struct command_entry commands[] =
{
		{
				"pwd",
				do_pwd,
				err_pwd
		},
		{
				"cd",
				do_cd,
				err_cd
		}
};

struct command_entry* fetch_command(const char* command_name)
{

	struct command_entry *cmdPtr;

	if(strcmp(command_name, commands[0].command_name) == 0){

		struct command_entry cmd = {
				commands[0].command_name,
				commands[0].command_func,
				commands[0].err
		};

		 cmdPtr = &cmd;
		return cmdPtr;

	}else if(strcmp(command_name, commands[1].command_name) == 0){

		struct command_entry cmd = {
				commands[1].command_name,
				commands[1].command_func,
				commands[1].err
		};

		cmdPtr = &cmd;
		return cmdPtr;
	}
	return NULL;
}

int do_pwd(int argc, char** argv)
{
	// TODO: Fill it
	if (getcwd(*argv, sizeof(argv)) != NULL) {

		printf("Current working dir: %s\n", *argv);
	} else {

		perror("getcwd() error");
		return -1;
	}
	return 0;

}

void err_pwd(int err_code)
{

}

int do_cd(int argc, char** argv)
{
	int value = chdir(argv[1]);

	if( value == 0){
		return 0;
	}else if(access(argv[0], F_OK) == 0){
		return 2;
	}

	return 0;
}

void err_cd(int err_code)
{
	if(err_code == 1){

		fprintf( stderr, " cd: no such file or directory: <directory name>" );

	}else if(err_code == 2){

		fprintf( stderr, "cd: not a directory: <directory name>");

	}
}

