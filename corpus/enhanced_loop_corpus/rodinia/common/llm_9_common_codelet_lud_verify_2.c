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
    for (j = 0; j < matrix_dim; j++) {
        float sum = 0;
        for (k = 0; k < i && k < j; k++) {
            float l = lu[i * matrix_dim + k];
            float u = lu[k * matrix_dim + j];
            sum += l * u;
        }
        if (i >= j)
            sum += lu[j * matrix_dim + j]; 
        tmp[i * matrix_dim + j] = sum;
    }
}
