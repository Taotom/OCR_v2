// Language - C
// Network  - Forward propagation
// Author   - Tao BLANCHETON



#include "forward.h"
#include "function.h"
#include "network.h"



// Calcul the output value of the nerons of the layer n with sigmoid function
struct matrix output_sigmoid(struct matrix input, struct matrix weight, struct matrix bias)
{
    struct matrix result = matrix_mult(input, weight);
    result = matrix_sum(result, bias);

    for (int k = 0 ; k < result.height*result.width ; k++)
    {
        result.table[k] = sigmoid(result.table[k]);
    }

    return result;
}

// Calcul the output value of the nerons of the layer n with softmax function
struct matrix output_softmax(struct matrix input, struct matrix weight, struct matrix bias)
{
    struct matrix result = matrix_mult(input, weight);
    result = matrix_sum(result, bias);
    result = softmax(result);

    return result;
}

// Do the forward propagation
struct matrix forward(struct network n, struct matrix input)
{
    struct matrix result = output_sigmoid(input, n.weight[0], n.bias[0]);

    for (int k = 1 ; k < n.layer-2 ; k++)
    {
        result = output_sigmoid(result, n.weight[k], n.bias[k]);
    }

    result = output_softmax(result, n.weight[n.layer-2], n.bias[n.layer-2]);

    return result;
}
