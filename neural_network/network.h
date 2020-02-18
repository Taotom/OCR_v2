// Language - C
// Network  - Main file
// Author   - Tao BLANCHETON



#ifndef NETWORK_H
#define NETWORK_H

#include "../lib/matrix.h"

struct network
{
    int layer;
    struct matrix *weight;
    struct matrix *bias;
};

struct network network_create(int layer, int *neuron);
void network_free(struct network n);

#endif
