#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 512;
double *A;
int lda;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    // Allocate A as a matrix of size at least (N x (K+1)) to cover all accesses: A[lda*j + (i-j)]
    // Maximum row index accessed: i <= N-1, and (i-j) <= K, so we need at least K+1 columns
    lda = K + 1;
    A = (double*)calloc(N * lda, sizeof(double));
    if (!A) exit(1);

    // X is accessed with indices involving incX and ix; total size must be large enough
    // Maximum absolute access: starting from ix and going up/down with incX steps
    int x_size = N * abs(incX) + 1;
    if (x_size < N) x_size = N;
    X = (double*)calloc(x_size, sizeof(double));
    if (!X) exit(1);

    // Initialize incX to a valid stride (common values are 1 or -1; use 1 for safety)
    incX = 1;

    // nonunit flag: set to 1 or 0; both cases should be safe
    nonunit = 1;

    // Initialize loop indices
    i = N;  // Will be decremented in loop condition
    ix = (incX > 0 ? 0 : (N - 1) * (-incX)) + (N - 1) * incX; // Start at last relevant position

    // Initialize X and A with some data to prevent NaN/inf and allow computation
    for (int idx = 0; idx < x_size; idx++) {
        X[idx] = 1.0;
    }
    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = 0.5;
    }
}