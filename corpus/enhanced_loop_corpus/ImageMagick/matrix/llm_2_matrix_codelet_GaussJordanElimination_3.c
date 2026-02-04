#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double **matrix;
extern  size_t rank;
extern long double **hp_matrix;
extern ssize_t i;
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    ssize_t stride = 2;
    for (i = 0; i < (ssize_t)rank; i++) {
        for (j = 0; j < (ssize_t)rank; j += stride) {
            if (j + 1 < (ssize_t)rank) {
                matrix[i][j] = (double)hp_matrix[i][j];
                matrix[i][j+1] = (double)hp_matrix[i][j+1];
            } else {
                matrix[i][j] = (double)hp_matrix[i][j];
            }
        }
    }
}
