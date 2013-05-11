/*
 * This file is part of the linuxapi project.
 * Copyright (C) 2011-2013 Mark Veltzer <mark.veltzer@gmail.com>
 *
 * The linuxapi package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * The linuxapi package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the GNU C Library; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307 USA.
 */

#include <firstinclude.h>
#include <unistd.h>	// for pathconf(2)
#include <stdio.h>	// for printf(3), fprintf(3)
#include <stdlib.h>	// for EXIT_SUCCESS, EXIT_FAILURE
#include <us_helper.h>	// for CHECK_NOT_M1(), __stringify()

/*
 * This example shows the various values returned by path conf for the folder you give it...
 */

#define PRINT_PATHCONF(path, name) printf("pathconf(\"%s\",%s)=%d\n", path, __stringify(name), CHECK_NOT_M1(pathconf(path, name)))

int main(int argc, char** argv, char** envp) {
	if(argc!=2) {
		fprintf(stderr, "%s: usage: %s [folder]\n", argv[0], argv[0]);
		return EXIT_FAILURE;
	}
	const char* path=argv[1];
	PRINT_PATHCONF(path, _PC_LINK_MAX);
	PRINT_PATHCONF(path, _PC_MAX_CANON);
	PRINT_PATHCONF(path, _PC_MAX_INPUT);
	PRINT_PATHCONF(path, _PC_NAME_MAX);
	PRINT_PATHCONF(path, _PC_PATH_MAX);
	PRINT_PATHCONF(path, _PC_PIPE_BUF);
	PRINT_PATHCONF(path, _PC_CHOWN_RESTRICTED);
	PRINT_PATHCONF(path, _PC_NO_TRUNC);
	PRINT_PATHCONF(path, _PC_VDISABLE);
	return EXIT_SUCCESS;
}