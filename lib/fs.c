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
#include "fs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int does_exefile_exists(const char* path)
{

	char* tmpPath = malloc(1024 * sizeof(char));

	if (path != NULL) {
		struct stat *buf = malloc(sizeof(struct stat));
		stat(path, buf);

		if(( buf->st_mode & S_IXUSR) == S_IXUSR){
			free(buf);
			free(tmpPath);
			return 1;
		}else{

			strcpy(tmpPath, "/bin/");
			strcat(tmpPath , path);
			stat(tmpPath, buf);

			if((buf->st_mode & S_IXUSR) == S_IXUSR){
				free(buf);
				free(tmpPath);
				return 1;
			}else{


				strcpy(tmpPath, "/usr/bin/");
				strcat(tmpPath, path);
				stat(tmpPath, buf);

				if((buf->st_mode & S_IXUSR) == S_IXUSR){

					free(buf);
					free(tmpPath);
					return 1;
				}
			}
		}
		free(buf);
		free(tmpPath);
	}

	free(tmpPath);

	return 0;
}
