#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 128;
double *A;
int lda;
double *X;
int incX;
int nonunit;
int i;
int j;
int ix;

void init_vars() {
    // Set parameters to ensure reasonable execution time (~0.01 sec) and memory footprint
    N = 2048;        // Size of the matrix/vector
    K = 128;         // Bandwidth parameter
    lda = K + 1;     // Leading dimension of A (band storage)
    incX = 1;        // Stride for X access
    nonunit = 1;     // Indicates whether diagonal is unit or not

    // Allocate arrays with appropriate sizes
    A = (double*)calloc(lda * N, sizeof(double));
    X = (double*)malloc(N * sizeof(double));

    // Initialize index variables
    i = N - 1;  // Start from last valid row index
    ix = (incX > 0 ? 0 : (N - 1) * (-incX)) + (N - 1) * incX;  // Point to last element in X under indexing rule

    // Initialize A and X with non-zero values to simulate realistic data
    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 1.0 + (rand() / (double)RAND_MAX);
        // Diagonal elements of A should be non-zero
        A[lda * idx + 0] = 2.0;  // Diagonal
        int k_max = ((K) < (N - idx) ? K : (N - idx));
        for (int k = 1; k < k_max; ++k) {
            A[lda * idx + k] = (rand() / (double)RAND_MAX) * 0.1;
        }
    }
}