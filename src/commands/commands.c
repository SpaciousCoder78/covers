/*
File: commands.c
Description: Commands of covers
License: MIT
Copyright (C) 2025 Aryan Karamtoth
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#define SIZE 300

char covers_info(int argc, char *argv[]){
	
	
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

char covers_install(int argc,char *argv[]){

    char installcmd[SIZE];

    if(argc<3){
        printf("covers install: Too few arguments supplied");
    }

    char *cmd = argv[1];
    char *pkgname = argv[2];

    int val = strcmp(cmd,"install");

    char precmd[SIZE] = "git clone ";

    char postcmd[SIZE] = " include/";

    strcat(precmd,pkgname);
    strcat(installcmd,precmd);
    strcat(installcmd,postcmd);
    strcat(installcmd,pkgname);
    if(val==0){
        system("mkdir include");
    
    }

    if(val==0){
        system(installcmd);
    }

    return 0;
}

