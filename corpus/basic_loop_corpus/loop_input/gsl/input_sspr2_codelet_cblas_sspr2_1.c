#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
float alpha;
float *X;
int incX;
float *Y;
int incY;
float *Ap;
int i;
int j;
int ix;
int iy;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime on modern CPU
    // The loop has O(N^2) complexity, so choose N accordingly.
    // Empirical tuning: N around 1000-2000 gives reasonable time without excessive memory.
    N = 1500;

    alpha = 1.5f;
    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;

    // Allocate arrays with appropriate sizes
    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    // Ap is a lower triangular matrix stored in packed form
    // Number of elements = N*(N+1)/2
    Ap = (float*)aligned_alloc(32, ((size_t)N * (N + 1) / 2) * sizeof(float));

    // Initialize X and Y with sample values
    for (int k = 0; k < N; k++) {
        X[k] = (float)(k % 128) * 0.01f;
        Y[k] = (float)((k + 64) % 128) * 0.01f;
    }

    // Initialize Ap to zero to avoid undefined behavior in += operations
    const size_t ap_size = ((size_t)N * (N + 1) / 2);
    for (size_t k = 0; k < ap_size; k++) {
        Ap[k] = 0.0f;
    }
}