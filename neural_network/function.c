// Language - C
// Network  - Activation functions
// Author   - Tao BLANCHETON



#include "function.h"

double sigmoid(double x)
{
    return exp(x)/(exp(x)+1);
}

double sigmoid_derivative(double x)
{
    double s = sigmoid(x);
    return s/(1-s);
}
