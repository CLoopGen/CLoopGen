#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix;
double *vector;
int n;
int i;
int j;
double *y;

void init_vars() {
    n = 1 << 14; // 16384 elements -> matrix size: 16384*16384*sizeof(double) ≈ 2GB, but inner loop runs only up to i, so effective work is about half -> adjust for ~0.01 sec runtime

    // Adjust n to get target execution time. For typical modern CPU, n=4096 gives reasonable ~0.01s workload.
    n = 4096;

    size_t matrix_size = n * n * sizeof(double);
    size_t vector_size = n * sizeof(double);

    matrix = (double*)calloc(n, n * sizeof(double));
    vector = (double*)calloc(n, sizeof(double));
    y      = (double*)calloc(n, sizeof(double));

    if (!matrix || !vector || !y) {
        exit(1);
    }

    // Initialize matrix with small lower triangular values to allow meaningful computation
    for (int idx = 0; idx < n; idx++) {
        int base = idx * n;
        for (int jdx = 0; jdx <= idx; jdx++) {
            matrix[base + jdx] = (double)(rand() % 100) / 100.0; // non-zero only in lower triangle including diagonal
        }
    }

    // Initialize vector with random values
    for (int idx = 0; idx < n; idx++) {
        vector[idx] = (double)(rand() % 100);
    }

    // Ensure y is zeroed initially as required by algorithm semantics
    for (int idx = 0; idx < n; idx++) {
        y[idx] = 0.0;
    }

    // Initialize loop indices
    i = 0;
    j = 0;
}