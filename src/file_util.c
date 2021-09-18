#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_util.h"

char* readFile(char* path) {
    FILE* file = fopen(path, "r");

    if(file == 0)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    char* content = (char*) malloc(sizeof(char) * (size + 1));
    content[size] = '\0';

    int index = 0;
    for(int index = 0; index < size; index++) {
        char read = fgetc(file);

        if(read == EOF)
            break;

        content[index] = read;
    }

    fclose(file);
    return content;
}

int writeFile(char* path, char* content) {
    FILE* file = fopen(path, "w+");

    if(file == 0)
        return 0;

    fputs(content, file);

    fclose(file);
}