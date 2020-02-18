// Language - C
// Network  - Activation functions
// Author   - Tao BLANCHETON



#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>
#include "../lib/matrix.h"

double sigmoid(double x);
double sigmoid_derivative(double x);
struct matrix softmax(struct matrix m);

#endif
