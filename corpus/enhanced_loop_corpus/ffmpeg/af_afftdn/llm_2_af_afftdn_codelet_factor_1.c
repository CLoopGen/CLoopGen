#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use row-major consecutive indexing with pointer arithmetic
    // Instead of accessing array[j + i * size] and similar, we precompute row starts to enable more sequential access
    for (int i = 0; i < size - 1; i++) {
        double* row_i = &array[i * size];  // Base pointer for row i
        double pivot = row_i[i];
        for (int j = i + 1; j < size; j++) {
            double* row_j = &array[j * size];  // Base pointer for row j
            double d = row_j[i] / pivot;
            row_j[i] = d;
            for (int k = i + 1; k < size; k++) {
                row_j[k] -= d * row_i[k];
            }
        }
    }
}
