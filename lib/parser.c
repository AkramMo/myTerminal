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
#include <stdbool.h>

#define BUFSIZE 1024

void parse_command(const char* input,
		int* argc, char*** argv)
{

	char command[50] = "";
	int counter = 0;
	int i = 0;
	bool quote = false;
	*argc = 0;


	argv[0] = malloc(BUFSIZE * sizeof(char ** ));

	while(*input != '\0'){

		while(*input != '\0' ){

			if(*input == '"'){
				quote = !quote;
			}

			if(*input != ' ' && *input != '"' && *input != '\n'){
				command[counter] = *input;
				*input++;
				counter++;
			}else if( *input == ' ' && quote){
				command[counter] = *input;
				*input++;
				counter++;
			}else{
				break;
			}
		}


		counter = 0;
		if( command[0] != 0){
			argv[0][i] = calloc(strlen(command), sizeof(char *));
			strncpy(argv[0][i], command, strlen(command) + 1);
			memset(command,0,50);
			*argc = *argc + 1;
			i++;
		}else{
			input++;
		}
	}
	argv[0][i++] = NULL;

}