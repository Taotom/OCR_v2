// Language - C
// Network  - Activation functions
// Author   - Tao BLANCHETON



#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>
#include "../lib/matrix.h"

struct matrix softmax(struct matrix m);
double relu(double x);
double relu_derivative(double x);

#endif
