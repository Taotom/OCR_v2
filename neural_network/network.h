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

struct train_dataset
{
    int len;
    struct matrix *train_table;
    struct matrix *result_table;
};

struct network network_create(int layer, int *neuron);
void network_free(struct network n);
void network_print(struct network n);
struct train_dataset dataset_create(char *path, int nb);

#endif
