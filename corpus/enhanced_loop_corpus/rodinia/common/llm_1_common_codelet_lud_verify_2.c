#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lu;
extern int matrix_dim;
extern int i;
extern int j;
extern int k;
extern float *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < matrix_dim; i++)
    for (k = 0; k < matrix_dim; k++)
        for (j = 0; j < matrix_dim; j++) {
            if (k > ((i) < (j) ? (i) : (j))) continue;
            float sum = (k == 0) ? 0 : tmp[i * matrix_dim + j];
            float l, u;
            if (i == k)
                l = 1;
            else
                l = lu[i * matrix_dim + k];
            u = lu[k * matrix_dim + j];
            sum += l * u;
            tmp[i * matrix_dim + j] = sum;
        }
}
