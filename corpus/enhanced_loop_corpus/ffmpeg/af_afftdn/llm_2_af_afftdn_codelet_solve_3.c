#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the matrix indexing to row-major layout
    // Assuming original matrix is column-major (Fortran-style), now simulate row-major access via index rewrite
    for (int i = size - 2; i >= 0; i--) {
        double d = vector[i];
        for (int j = i + 1; j < size; j++)
            d -= matrix[i * size + j] * vector[j];  // Changed from [i + j*size] to [i*size + j]
        vector[i] = d / matrix[i * size + i];
    }
}
