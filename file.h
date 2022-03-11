#ifndef CMM_FILE_H
#define CMM_FILE_H

char *read_file(const char *path){
    FILE *mainFile;
    mainFile = fopen(path,"r");
    if(mainFile == NULL){
        printf("Compiler: '%s' No such file or directory\n",path);
        exit(0);
    }

    fseek(mainFile,SEEK_SET,SEEK_END);
    int size = ftell(mainFile);
    char *data = malloc(size*sizeof(char));
    char ch;
    mainFile = fopen(path,"r");
    int i = 0;
    do {
        ch = fgetc(mainFile);
        data[i] = ch;
        i++;
    } while (ch != EOF);
    data[size] = '\0';
    fclose(mainFile);
    
    return data;
}

#endif