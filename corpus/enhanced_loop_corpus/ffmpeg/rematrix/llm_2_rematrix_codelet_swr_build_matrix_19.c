#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double rematrix_volume;
extern double *matrix_param;
extern int stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // This accesses memory in a column-major fashion, improving spatial locality if the matrix is stored row-major
    for (j = 0; j < 64; j++)
        for (i = 0; i < 64; i++) {
            matrix_param[stride * i + j] *= rematrix_volume;
        }
}
