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
#include "../libs/tomlc17.h"

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
		printf("Version: 1.0.0\n");
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
        
        FILE *fp;

        char buf[128];
        strcpy(buf, "    \"");
        strcat(buf, pkgname);
        strcat(buf, "\",\n");

        fp = fopen("carriage-build.toml","a+");

        if(fp == NULL){
            printf("Error: carriage-build.toml not opened\n");
        }
        else{
            printf("covers: installing carriage....\n");
            fputs(buf, fp);
            fclose(fp);

            printf("covers: carriage successfully installed!\n");
        }
    }

    return 0;
}

//create a new carriage
char covers_init(int argc,char *argv[]){
    //hard coded minimum arguments of 3
	if (argc < 3){
		printf("covers: Too few arguments supplied\n");
        exit(0); //quit the program to avoid seg faults
	}

    char *cmd = argv[1]; //get the arg used here it is "init"

    //check if user actually typed init
    int val = strcmp(cmd,"init");
    //if they did
    if (val==0){

    char carriageName[32];
    char carriageVersion[8];
    char authorName[64];
    char carriageLicense[32];

    //get all carriage details
    printf("Enter the name of project: \n");
    scanf("%s",carriageName);
    printf("Enter the version: \n");
    scanf("%s",carriageVersion);
    printf("Enter the Author's Name: \n");
    scanf("%s",authorName);
    printf("Enter Project License: \n");
    scanf("%s",carriageLicense);


    FILE *fp; //creating a file pointer

        //insert all details into toml
    char config[512] = "[carriage.config]\n";
    strcat(config,"name = \"");
    strcat(config,carriageName);
    strcat(config,"\"\n");
    strcat(config,"version = \"");
    strcat(config,carriageVersion);
    strcat(config,"\"\n");
    strcat(config,"author = \"");
    strcat(config,authorName);
    strcat(config,"\"\n");
    strcat(config,"license = \"");
    strcat(config,carriageLicense);
    strcat(config,"\"\n\n");
    strcat(config,"[carriage.dependencies]\n"
                        "dependencies = [\n");

    //create the toml file
    fp = fopen("carriage-build.toml","w");
    
    //write the juicy data into it
    if(fp == NULL){
        printf("Error: carriage-build.toml not opened\n");
    }
    else{
        printf("covers: generating carriage-build.toml....\n");
        fputs(config,fp);
        fclose(fp);

        printf("covers: carriage-build.toml successfully generated!\n");
    }
}
    return 0;
}

void error(const char *msg, const char *msg1) {
        fprintf(stderr, "ERROR: %s%s\n", msg, msg1 ? msg1 : "");
        exit(1);
    }

char covers_install_deps(int argc,char *argv[]){


    if (argc < 3){
		printf("covers: Too few arguments supplied\n");
        exit(0); //quit the program to avoid seg faults
	}

    char *cmd = argv[1];

    int val = strcmp(cmd,"install-deps");

    if (val==0){
        toml_result_t result = toml_parse_file_ex("carriage-build.toml");
        // Check for parse error
        if (!result.ok) {
        error(result.errmsg, 0);
        }

        // Extract values
        toml_datum_t deps = toml_seek(result.toptab, "carriage.dependencies.dependencies");
        
        if (deps.type != TOML_ARRAY) {
            error("missing or invalid 'carriage.dependencies.dependencies' property in config", 0);
        }
        for (int i = 0; i < deps.u.arr.size; i++) {
            toml_datum_t cars = deps.u.arr.elem[i];
            printf("covers: installing dependency '%s'...\n", cars.u.s);
                
            // Build install command
            char installcmd[SIZE];
            memset(installcmd, 0, sizeof(installcmd));
                
            char precmd[SIZE] = "git clone https://codeberg.org/covers/";
            char postcmd[SIZE] = " include/";
                
            strcat(precmd, cars.u.s);
            strcat(installcmd, precmd);
            strcat(installcmd, postcmd);
            strcat(installcmd, cars.u.s);
            system(installcmd);
                printf("covers: dependency '%s' installed!\n", cars.u.s);
            
        }
        printf("covers: all dependencies installed successfully!\n");
        toml_free(result);
    }
    return 0;
}

//finalize dependencies array in carriage-build.toml
char covers_finalize_dependencies(int argc,char *argv[]){

    if (argc < 3){
		printf("covers: Too few arguments supplied\n");
        exit(0); //quit the program to avoid seg faults
	}

    char *cmd = argv[1];

    int val = strcmp(cmd,"finalize");

    if (val==0){

    

    FILE *fp = fopen("carriage-build.toml","a");
    
    if(fp == NULL){
        printf("Error: carriage-build.toml not opened\n");
        return 1;
    }
    
    fputs("]\n", fp);
    fclose(fp);
    }
    return 0;
}