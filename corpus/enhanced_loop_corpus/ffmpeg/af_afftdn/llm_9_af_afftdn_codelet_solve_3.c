#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = size - 2; i >= 0; i--) {
        double d = vector[i];
        int unroll_factor = 4;
        int remainder = (size - (i + 1)) % unroll_factor;
        int j = i + 1;

        for (int r = 0; r < remainder; r++, j++)
            d -= matrix[i + j * size] * vector[j];

        for (; j <= size - unroll_factor; j += unroll_factor) {
            d -= matrix[i + j * size] * vector[j]
                 + matrix[i + (j+1) * size] * vector[j+1]
                 + matrix[i + (j+2) * size] * vector[j+2]
                 + matrix[i + (j+3) * size] * vector[j+3];
        }

        for (; j < size; j++)
            d -= matrix[i + j * size] * vector[j];

        vector[i] = d / matrix[i + i * size];
    }
}
