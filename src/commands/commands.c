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
		printf("covers: Too few arguments supplied\n");
        exit(0);
	}
	char *var = argv[1];	

	int val = strcmp(var,"version");

	if (val==0) {
        printf("====================================\n");
        printf("             Covers                 \n\n");
        printf("   A Package/Library Manager for C\n\n");
		printf("Version: 0.1.0\n");
        printf("License: MIT\n");
        printf("Author: Aryan Karamtoth\n");
        printf("Git Browse: https://codeberg.org/covers\n");
        printf("Submit a Carriage: https://codeberg.org/covers/submitcarriages/issues\n");
	}

	return 0;

}

char covers_install(int argc,char *argv[]){

    char installcmd[SIZE];

    if(argc<3){
        printf("covers: Too few arguments supplied");
        exit(0);
    }

    char *cmd = argv[1];
    char *pkgname = argv[2];

    int val = strcmp(cmd,"install");

    char precmd[SIZE] = "git clone https://codeberg.org/covers/";

    char postcmd[SIZE] = " include/";

    strcat(precmd,pkgname);
    strcat(installcmd,precmd);
    strcat(installcmd,postcmd);
    strcat(installcmd,pkgname);
    printf("%c",*installcmd);
    if(val==0){
        system("mkdir include");
    
    }

    if(val==0){
        system(installcmd);
    }

    return 0;
}

