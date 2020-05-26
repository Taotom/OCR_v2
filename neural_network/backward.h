// Language - C
// Network  - Back propagation
// Author   - Tao BLANCHETON



#ifndef BACKWARD_H
#define BACKWARD_H

#include "../lib/matrix.h"
#include "network.h"

struct train_dataset shuffle(struct train_dataset train);
void weight_update(struct network n, struct matrix *error);
void backward(struct network);

#endif
