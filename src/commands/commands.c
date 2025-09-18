/*
File: commands.c
Description: Commands of CLPM
License: GNU GPL-3
Copyright (C) 2025 Aryan Karamtoth
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#define SIZE 300

char clpm_info(int argc, char *argv[]){
	
	
	if (argc < 3){
		printf("Too few arguments supplied\n");
		return 0;
	}
	char *var = argv[1];	

	int val = strcmp(var,"version");

	if (val==0) {
		printf("Version 1.0\n");
	}

	return 0;

}

char clpm_install(int argc,char *argv[]){

    char installcmd[SIZE];

    if(argc<3){
        printf("clpm install: Too few arguments supplied");
    }

    char *cmd = argv[1];
    char *pkgname = argv[2];

    int val = strcmp(cmd,"install");

    char precmd[SIZE] = "git clone ";

    strcat(precmd,pkgname);
    strcat(installcmd,precmd);

    if(val==0){
        system("cd ../");
        system(installcmd);
    }
    return 0;
}

