// Language - C
// Network  - Back propagation
// Author   - Tao BLANCHETON



#include "backward.h"
#include <stdlib.h>



struct train_dataset shuffle(struct train_dataset train)
{
    for (int k = 0 ; k < train.len-1 ; k++)
    {
        int new = k + rand() / (RAND_MAX / (train.len - k) + 1);

        struct matrix temp = train.train_table[new];
        train.train_table[new] = train.train_table[k];
        train.train_table[k] = temp;

        temp = train.result_table[new];
        train.result_table[new] = train.result_table[k];
        train.result_table[k] = temp;
    }
}
