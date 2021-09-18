#include <stdio.h>
#include <stdlib.h>
#include "cimple_ai.h"
#include "file_util.h"

#define MAIN_INVALID_ARGUMENTS -1
#define MAIN_SUCCESS 0

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Name a file to read as argument!\n");
        return MAIN_INVALID_ARGUMENTS;
    }

    char* content = readFile(argv[1]);

    if(content == 0) {
        printf("File could not be read!\n");
        return MAIN_INVALID_ARGUMENTS;
    }

    printf("%s\n", content);
    free(content);

    return MAIN_SUCCESS;
}

/*int main(int argc, char** argv) {
    if(argc <= 1) {
        printf("Use numbers as arguments!\n");
        return MAIN_INVALID_ARGUMENTS;
    }

    int* layerSizes = (int*) malloc(sizeof(int) * (argc - 1));

    for(int index = 0; index < argc - 1; index++)
        layerSizes[index] = atoi(argv[index + 1]);

    CAINetwork network;

    caiConstruct(&network, argc - 1, layerSizes);
    free(layerSizes);

    caiPrint(&network);
    caiDestroy(&network);

    return MAIN_SUCCESS;
}*/