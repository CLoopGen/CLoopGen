#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing matrix by row-major indexing (j + i * size), we precompute strides and access vector with a fixed offset pattern.
    for (int i = 0; i < size - 1; i++) {
        double vi = vector[i]; // Load once to enable reuse
        for (int j = i + 1; j < size; j++) {
            int idx = i * size + j; // Transposed access: treat matrix as column-major for strided reads
            double d = matrix[idx];
            vector[j] -= d * vi;
        }
    }
}
