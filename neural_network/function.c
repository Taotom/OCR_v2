// Language - C
// Network  - Activation functions
// Author   - Tao BLANCHETON



#include "function.h"
#include <err.h>
#include <stdio.h>



// Sigmoid function
double sigmoid(double x)
{
    return exp(x)/(exp(x)+1);
}

// Sigmoid derivative function
double sigmoid_derivative(double x)
{
    double s = sigmoid(x);
    return s/(1-s);
}

// Softmax function
struct matrix softmax(struct matrix m)
{
    if (m.height != 1)
    {
        errx(1, "Softmax: Wrong size");
    }

    struct matrix m_soft = matrix_create(m.height, m.width, 0);
    double denum = 0;

    for (int k = 0 ; k < m_soft.width ; k++)
    {
        denum += exp(m.table[k]);
    }

    for (int k = 0 ; k < m_soft.width ; k++)
    {
        m_soft.table[k] = exp(m.table[k])/denum;
    }

    return m_soft;
}
