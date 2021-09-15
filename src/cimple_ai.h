#ifndef CIMPLE_AI_H
#define CIMPLE_AI_H

#define CAI_SUCCESS 1
#define CAI_INVALID_INPUT -1

typedef struct CAINetworkStruct {
    int layerCount;
    int* neuronCounts;
    float** weights;
} CAINetwork;

int caiConstruct(CAINetwork* network, int layerCount, int* neuronCounts);
int caiDestroy(CAINetwork* network);
int caiPrint(CAINetwork* network);

#endif