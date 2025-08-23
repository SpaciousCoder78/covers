/*
File: calp_info.c
Description: Info of CALP 
License: GNU GPL-3
Copyright (C) 2025 Aryan Karamtoth
*/

#include "commands.h"
#include <stdlib.h>
#include <stdio.h>

char calp_info(int argc, char *argv[]){
	if (argc > 1){
		printf("Too few arguments supplied");
	}



	else {
		printf("Version 1.0");
	}

	return 0;

}


int main(int argc, char *argv[]){
	if (argc > 1){
		printf("Too few arguments supplied");
	}

	else {
		printf("Version 1.0");
	}

	return 0;

}

