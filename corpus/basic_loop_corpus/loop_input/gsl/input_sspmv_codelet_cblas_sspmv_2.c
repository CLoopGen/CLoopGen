#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float alpha = 1.5f;

float *Ap = NULL;
float *X = NULL;
int incX = 1;
float *Y = NULL;
int incY = 1;
int i = 0;
int j = 0;
int ix = 0;
int iy = 0;

void init_vars() {
    // Allocate arrays with size based on N
    // Ap is a packed upper triangular matrix stored in row-major format
    // Number of elements in packed Ap: N*(N+1)/2
    const int ap_size = N * (N + 1) / 2;
    Ap = (float*)aligned_alloc(32, ap_size * sizeof(float));
    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    // Initialize all data to prevent NaN or extreme values affecting timing
    for (int k = 0; k < ap_size; k++) {
        Ap[k] = 1.0f / (1.0f + k % 17);
    }
    for (int k = 0; k < N; k++) {
        X[k] = 1.0f / (1.0f + k % 13);
        Y[k] = 1.0f / (1.0f + k % 19);
    }

    // Set index pointers to start
    ix = 0;
    iy = 0;

    // Ensure incX and incY are positive to keep indexing simple and safe
    incX = 1;
    incY = 1;
}