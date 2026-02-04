#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 2048;
float *A;
int lda;
float *X;
int incX;
int nonunit;
int ix;
int jx;
int i;
int j;

void init_vars() {
    // Set reasonable values for parameters
    lda = N;
    incX = 1;
    nonunit = 1;
    ix = 0;
    jx = 0;
    i = 0;
    j = 0;

    // Allocate matrices and vectors
    A = (float*)aligned_alloc(32, sizeof(float) * N * N);
    X = (float*)aligned_alloc(32, sizeof(float) * N);

    // Initialize A as lower triangular with positive diagonal for stability
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col <= row) {
                A[lda * col + row] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f; // Lower triangular
            } else {
                A[lda * col + row] = 0.0f;
            }
        }
        // Ensure diagonal is not zero, and scale for numerical stability
        A[lda * row + row] += 2.0f;
    }

    // Initialize X with random values
    for (int k = 0; k < N; k++) {
        X[k] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
}