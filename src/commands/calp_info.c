/*
File: calp_info.c
Description: Info of CALP 
License: GNU GPL-3
Copyright (C) 2025 Aryan Karamtoth
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"

char calp_info(int argc, char *argv[]){
	
	
	if (argc < 2){
		printf("Too few arguments supplied");
		return 0;
	}
	char *var = argv[1];	

	int val = strcmp(var,"version");

	if (val==0) {
		printf("Version 1.0");
	}

	return 0;

}


