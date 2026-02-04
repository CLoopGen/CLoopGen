#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix;
double *vector;
int size;

void init_vars() {
    size = 1024; // Choose size such that total operations are around O(n^2), n=1024 gives ~500k iterations, matrix size ~8MB

    matrix = (double*)aligned_alloc(32, size * size * sizeof(double));
    vector = (double*)aligned_alloc(32, size * sizeof(double));

    for (int i = 0; i < size * size; i++) {
        matrix[i] = (double)(i % 127) / 10.0;
    }
    for (int i = 0; i < size; i++) {
        vector[i] = (double)((i + 1) % 89) / 5.0;
    }
}