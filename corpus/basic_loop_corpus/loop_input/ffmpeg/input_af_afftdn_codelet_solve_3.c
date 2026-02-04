#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix;
double *vector;
int size;

void init_vars() {
    size = 1024; // Choose size such that total data is ~8MB (1024*1024*8 bytes for matrix + 1024*8 for vector)

    matrix = (double*)aligned_alloc(32, size * size * sizeof(double));
    vector = (double*)aligned_alloc(32, size * sizeof(double));

    for (int i = 0; i < size * size; i++) {
        matrix[i] = 1.0 + (i % size == i / size ? 0.1 : 0.0); // Diagonal slightly larger to avoid division by small numbers
    }

    for (int i = 0; i < size; i++) {
        vector[i] = 1.0;
    }
}