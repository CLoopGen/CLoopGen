#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

float *A;
int lda;

float *X;
int incX;

int i;
int j;
int nonunit;
int ix;

void init_vars() {
    // Set problem size based on performance target (~0.01 sec)
    // For double nested loop with ~N^2/2 operations, N=2048 gives ~2M iterations which is reasonable
    
    lda = N; // leading dimension of A

    // Allocate arrays
    A = (float*)aligned_alloc(32, sizeof(float) * lda * N);
    X = (float*)aligned_alloc(32, sizeof(float) * N);

    // Initialize array elements to prevent undefined behavior
    for (int idx = 0; idx < N * N; idx++) {
        A[idx] = 1.0f + (idx % 100) * 0.01f;
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx] = 0.5f + idx * 0.001f;
    }

    // Initialize scalar parameters
    incX = 1;          // typical stride
    nonunit = 1;       // enables the if branch
    ix = (incX > 0 ? 0 : (N - 1) * (-incX)) + (N - 1) * incX; // consistent with final index usage
}