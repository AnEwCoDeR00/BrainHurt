#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/file.h"
#include "include/compile.h"
/*
C-- is a language designed to make your brain damage
see the compile.h for commands 
*/

int main(int argc , char **argv){
    //Checks
    if(argc < 1){
        printf("Compiler: No input files\n");
        exit(0);
    }
    if(argc > 2){
        printf("Compiler: More than one arguments\n");
        
        exit(0);
    }
    char fileEnd[] = {argv[1][strlen(argv[1]) - 4],argv[1][strlen(argv[1]) - 3],argv[1][strlen(argv[1])-2],argv[1][strlen(argv[1])-1],argv[1][strlen(argv[1])],'\0'};

    if(strcmp(fileEnd,"hurt") != 0){
        printf("Compiler: Invalid File type\n");
        exit(0);
    }
    //opening the file and reading it
    char *data = read_file(argv[1]);

    compile(data);
    free(data);
}