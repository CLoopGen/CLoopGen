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
        float l, u;
        int idx_i = i * matrix_dim;
        int idx_j = j;
        for (k = 0; k <= ((i) < (j) ? (i) : (j)); k++) {
            if (i == k)
                l = 1;
            else
                l = lu[idx_i + k];
            u = lu[k * matrix_dim + idx_j];
            sum += l * u;
        }
        tmp[idx_i + j] = sum;
    }

}
