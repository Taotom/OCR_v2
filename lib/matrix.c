// Language  - C
// Structure - Matrix
// Author    - Tao BLANCHETON



#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

// Return an random double between [min ; max [
double random_double(double min, double max)
{
    return min + (rand() / (RAND_MAX / (max - min)));
}

// Put the value stored in the matrix m at the coordinates (i, j) in result
double matrix_get(struct matrix m, int i, int j)
{
    if (i > m.height || j > m.width)
    {
        errx(1, "matrix_get: Out of bound");
    }

    return m.table[i*m.width+j];
}

// Put the value in the matrix m at the coordinates (i, j)
void matrix_put(struct matrix m, int i, int j, double value)
{
    if (i > m.height || j > m.width)
    {
        errx(1, "matrix_put: Out of bound");
    }

    m.table[i*m.width+j] = value;
}

// Return a new matrix of size (height, width) filled with value
struct matrix matrix_create(int height, int width, double value)
{
    struct matrix m;

    m.height = height;
    m.width = width;
    m.table = malloc(height * width * sizeof(double));

    if (m.table == NULL)
    {
        errx(1, "matrix_create: Not enough memory");
    }

    for (int k = 0 ; k < height*width ; k++)
    {
        m.table[k] = value;
    }

    return m;
}

// Return a new matrix of size (height, width) filled with random value between [min ; max [
struct matrix matrix_aleacreate(int height, int width, double min, double max)
{
    struct matrix m;

    m.height = height;
    m.width = width;
    m.table = malloc(height * width * sizeof(double));

    if (m.table == NULL)
    {
        errx(1, "matrix_create: Not enough memory");
    }

    for (int k = 0 ; k < height*width ; k++)
    {
        m.table[k] = random_double(min, max);
    }

    return m;
}

// Free the memory taken by the matrix m
void matrix_free(struct matrix m)
{
    if (m.table == NULL)
    {
        errx(1, "matrix_free: The matrix doesn't exist");
    }

    free(m.table);
}

// Return the sum of matrix m1 and m2
struct matrix matrix_sum(struct matrix m1, struct matrix m2)
{
    if (m1.height != m2.height || m1.width != m2.width)
    {
        errx(1, "matrix_sum: Wrong size");
    }

    struct matrix result = matrix_create(m1.height, m1.width, 0);

    for (int k = 0 ; k < result.height*result.width ; k++)
    {
        result.table[k] = m1.table[k] + m2.table[k];
    }

    return result;
}

// Return the result of the multiplication of matrix m1 by m2
struct matrix matrix_mult(struct matrix m1, struct matrix m2)
{
   if (m1.width != m2.height)
   {
        errx(1, "matrix_mult: Wrong size");
   }

   struct matrix result = matrix_create(m1.height, m2.width, 0);

   for (int i = 0 ; i < result.height ; i++)
   {
        for (int j = 0 ; j < result.width ; j++)
        {
            for (int k = 0 ; k < m1.width ; k++)
            {
                result.table[i*result.width+j] += m1.table[i*m1.width+k] * m2.table[k*m2.width+i];
            }
        }
   }

   return result;
}

// Return the result of the elementwise of matrix m1 and m2
struct matrix matrix_eltwise(struct matrix m1, struct matrix m2)
{
    if (m1.height != m2.height || m1.width != m2.width)
    {
        errx(1, "matrix_eltwise: Wrong size");
    }

    struct matrix result = matrix_create(m1.height, m1.width, 0);

    for (int k = 0 ; k < m1.height * m1.width ; k++)
    {
        result.table[k] = m1.table[k] * m2.table[k];
    }

    return result;
}

// Return the result of the sum between a matrix m and a value
struct matrix matrix_eltsum(struct matrix m, double value)
{
    struct matrix result = matrix_create(m.height, m.width, 0);

    for (int k = 0 ; k < result.height * result.width ; k++)
    {
        result.table[k] = m.table[k] + value;
    }

    return result;
}

// Return the result of the multiplication between a matrix m and a value
struct matrix matrix_eltmult(struct matrix m, double value)
{
    struct matrix result = matrix_create(m.height, m.width, 0);

    for (int k = 0 ; k < result.height * result.width ; k++)
    {
        result.table[k] = m.table[k] * value;
    }

    return result;
}


void matrix_print(struct matrix m)
{
    printf("Height: %i | Width: %i\n\n", m.height, m.width);

    for (int i = 0 ; i < m.height ; i++)
    {
        for (int j = 0 ; j < m.width ; j++)
        {
            printf("| %.3f ", matrix_get(m, i, j));
        }

        printf("|\n");
    }

    printf("\n\n\n");
}
