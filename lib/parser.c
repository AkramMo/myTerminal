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
#include "parser.h"
#include "string.h"
#include "stdlib.h"

void parse_command(const char* input,
		int* argc, char*** argv)
{

	char command[10] = "";
	int counter = 0;
	int i = 0;
	int j = 0;
	*argc = 0;



	//	argv =  malloc( sizeof(char ***));
	//	*argv =  malloc(row * sizeof(char **));
	//	*argv[0] =  malloc(row * col * sizeof(char **));
	//	*argc = 1;

	argv[0] = malloc(50 * sizeof(char ** ));
	while(*input != '\0'){

		while(*input != '/' && *input != '\0' && *input != ' '){
			command[counter] = *input;
			*input++;
			counter++;
		}

		counter = 0;
		if( command[0] != 0){
			argv[0][i] = calloc(strlen(command) + 1, sizeof(char *));
			strncpy(argv[0][i], command, strlen(command) + 1);
			memset(command,0,10);
			*argc = *argc + 1;
			i++;
		}else{
			input++;
		}
	}
}


