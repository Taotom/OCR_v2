// Language - C
// Network  - Forward propagation
// Author   - Tao BLANCHETON



#include "forward.h"
#include "function.h"
#include "network.h"



// Calcul the output value of the nerons of the layer n
struct matrix output(struct matrix input, struct matrix weight, struct matrix bias)
{
    struct matrix result = matrix_mult(input, weight);

    for (int k = 0 ; k < result.height*result.width ; k++)
    {
        result.table[k] = matrix_sum(result, bias);
        result.table[k] = sigmoid(result.table[k]);
    }

    return result;
}

// Do the forward propagation
struct matrix forward(struct network n, struct matrix input)
{
    struct matrix result = output(input, n.weight[0], n.bias[0]);

    for (int k = 1 ; k < layer ; k++)
    {
        result = output(result, n.weight[k], n.bias[k]);
    }

    return result;
}
