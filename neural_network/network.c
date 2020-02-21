// Language - C
// Network  - Main file
// Author   - Tao BLANCHETON



#include "network.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>



// Create a new neural network
struct network network_create(int layer, int *neuron)
{
    struct network n;

    n.layer = layer;
    n.weight = malloc((layer-1)*sizeof(struct matrix));
    n.bias = malloc((layer-1)*sizeof(struct matrix));

    if (n.weight == NULL || n.bias == NULL)
    {
        errx(1, "network_create: Not enough memory");
    }

    for (int k = 0 ; k < layer-1 ; k++)
    {
        n.weight[k] = matrix_aleacreate(neuron[k], neuron[k+1], 0, 1);
        n.bias[k] = matrix_aleacreate(1, neuron[k+1], 0, 1);
    }

    return n;
}

// Free a neural network
void network_free(struct network n)
{
    free(n.weight);
    free(n.bias);
}

// Print a neural network
void network_print(struct network n)
{
    for (int k = 0 ; k < n.layer-1 ; k++)
    {
        printf("Layer %i -> %i:\n\n", k+1, k+2);
        matrix_print(n.weight[k]);
        matrix_print(n.bias[k]);
        printf("\n\n");
    }
}
