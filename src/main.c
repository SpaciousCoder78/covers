/*
File: main.c
Description: Main file
License: MIT
Copyright (C) 2025 Aryan Karamtoth
*/

#include <stdio.h>
#include "commands/commands.h"

//main func
int main(int argc, char *argv[]) {
	
	//load all commands
	 covers_info(argc,argv);
	 covers_install(argc,argv);
	 covers_init(argc,argv);
	 covers_finalize_dependencies(argc,argv);
	 covers_install_deps(argc,argv);

}
