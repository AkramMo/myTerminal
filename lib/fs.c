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

int does_exefile_exists(const char* path)
{

	if (path != NULL) {
		struct stat statStruct;

		if(stat(path, &statStruct) == 0 && statStruct.st_mode == S_IXUSR){
			return 1;
		}
	}
	return 0;
}
