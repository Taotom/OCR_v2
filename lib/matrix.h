// Language  - C
// Structure - Matrix
// Author    - Tao BLANCHETON



// INFO
// i: variable define into [0;height]
// j: variable define into [0;width]
// operation between matrix: m1->m2->result



#ifndef MATRIX_H
#define MATRIX_H

struct matrix
{
    double *table;
    int height;
    int width;
};

double matrix_get(struct matrix m, int i, int j);
void matrix_put(struct matrix m, int i, int j, double value);

struct matrix matrix_create(int height, int width, double value);
struct matrix matrix_aleacreate(int height, int width, double min, double max);
void matrix_free(struct matrix m);

struct matrix matrix_sum(struct matrix m1, struct matrix m2);
struct matrix matrix_mult(struct matrix m1, struct matrix m2);
struct matrix matrix_eltwise(struct matrix m1, struct matrix m2);

struct matrix matrix_eltsum(struct matrix m, double value);
struct matrix matrix_eltmult(struct matrix m, double value);


void matrix_print(struct matrix m);
#endif
