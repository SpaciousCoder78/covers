/*
File: commands.c
Description: Commands of covers
License: MIT
Copyright (C) 2025 Aryan Karamtoth
*/

//header file dump
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#define SIZE 300 //creating a static buffer of 300 chars for string manipulations


//functions for covers version -v
char covers_info(int argc, char *argv[]){
	
	//hard coded minimum arguments of 3
	if (argc < 3){
		printf("covers: Too few arguments supplied\n");
        exit(0); //quit the program to avoid seg faults
	}

	char *var = argv[1]; //get the command used into a character pointer

	int val = strcmp(var,"version"); //check if the user wants version details

    //if the user did type "version"
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

//install a package from official repo
char covers_install(int argc,char *argv[]){

    //create a command string buffer
    char installcmd[SIZE];

    //hard coded args again
    if(argc<3){
        printf("covers: Too few arguments supplied");
        exit(0);
    }

    char *cmd = argv[1]; //get the command used, here its "install"
    char *pkgname = argv[2]; //get the package name used, its dynamic

    int val = strcmp(cmd,"install"); //check if the user actually typed "install"

    //piece of install command
    char precmd[SIZE] = "git clone https://codeberg.org/covers/";

    //another piece
    char postcmd[SIZE] = " include/";

    //concat git url and package name
    strcat(precmd,pkgname); 
    //concat install and full git url
    strcat(installcmd,precmd);
    //concat install command and folder location
    strcat(installcmd,postcmd);
    //finally concat the package name to the final command
    strcat(installcmd,pkgname);

    //if the user did type install, make a include/ folder
    if(val==0){
        system("mkdir include");
    
    }

    //run the frankenstein-ed install command
    if(val==0){
        system(installcmd);
    }

    return 0;
}

