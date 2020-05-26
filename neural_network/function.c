// Language - C
// Network  - Activation functions
// Author   - Tao BLANCHETON



#include "function.h"
#include <err.h>
#include <stdio.h>



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

double relu(double x)
{
    return (x < 0) ? 0 : x;
}

double relu_derivative(double x)
{
    return (x <= 0) ? 0 : 1;
}
