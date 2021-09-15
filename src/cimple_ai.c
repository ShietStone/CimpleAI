#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cimple_ai.h"

int caiConstruct(CAINetwork* network, int layerCount, int* neuronCounts) {
    if(network <= 0 || layerCount <= 0)
        return CAI_INVALID_INPUT;

    for(int index = 0; index < layerCount; index++)
        if(neuronCounts[index] <= 0)
            return CAI_INVALID_INPUT;

    int* neuronCountsCopy = (int*) malloc(sizeof(int) * layerCount);
    memcpy(neuronCountsCopy, neuronCounts, sizeof(int) * layerCount);

    float** weights = (float**) malloc(sizeof(float*) * layerCount);

    for(int index = 0; index < layerCount; index++)
        weights[index] = (float*) malloc(sizeof(float) * neuronCounts[index]);

    network->layerCount = layerCount;
    network->neuronCounts = neuronCountsCopy;
    network->weights = weights;

    return CAI_SUCCESS;
}

int caiDestroy(CAINetwork* network) {
    if(network <= 0 || network->layerCount == 0)
        return CAI_INVALID_INPUT;

    for(int index = 0; index < network->layerCount; index++)
        free(network->weights[index]);

    free(network->neuronCounts);
    free(network->weights);

    network->layerCount = 0;
    network->neuronCounts = 0;
    network->weights = 0;

    return CAI_SUCCESS;
}

int caiPrint(CAINetwork* network) {
     if(network <= 0 || network->layerCount == 0)
        return CAI_INVALID_INPUT;

    for(int layerIdx = 0; layerIdx < network->layerCount; layerIdx++) {
        for(int neuronIdx = 0; neuronIdx < network->neuronCounts[layerIdx]; neuronIdx++)
            printf("%f ", network->weights[layerIdx][neuronIdx]);

        printf("\n");
    }

    return CAI_SUCCESS;
}