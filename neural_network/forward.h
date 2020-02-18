// Language - C
// Network  - Forward propagation
// Author   - Tao BLANCHETON



#ifndef FORWARD_H
#define FORWARD_H

#include "../lib/matrix.h"
#include "network.h"

struct matrix output_sigmoid(struct matrix input, struct matrix weight, struct matrix bias);
struct matrix output_softmax(struct matrix input, struct matrix weight, struct matrix bias);
struct matrix forward(struct network n, struct matrix input);

#endif
