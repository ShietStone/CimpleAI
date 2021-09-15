#include <stdio.h>
#include <stdlib.h>
#include "cimple_ai.h"

#define MAIN_INVALID_ARGUMENTS -1
#define MAIN_SUCCESS 0

int main(int argc, char** argv) {
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
}