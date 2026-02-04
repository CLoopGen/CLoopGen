#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float alpha = 1.5f;

float *Ap;
float *X;
int incX;
float *Y;
int incY;
int i;
int j;
int ix;
int iy;

void init_vars() {
    // Allocate arrays with sizes to ensure ~O(N^2) operations take ~0.01s
    // For N=2048, Ap is triangular: N*(N+1)/2 elements (~2M floats, ~8MB)
    // X and Y are vectors of size N (each ~8KB)
    
    const size_t ap_size = (size_t)N * (N + 1) / 2;
    Ap = (float*)calloc(ap_size, sizeof(float));
    X = (float*)calloc(N, sizeof(float));
    Y = (float*)calloc(N, sizeof(float));

    // Initialize data to non-zero for realistic computation
    for (int k = 0; k < N; ++k) {
        X[k] = 1.0f / (k + 1);
        Y[k] = 0.0f;
    }
    for (size_t k = 0; k < ap_size; ++k) {
        Ap[k] = (k % 17) * 0.1f;
    }

    // Set increments
    incX = 1;
    incY = 1;

    // Initialize loop indices
    i = 0;
    j = 0;
    ix = 0;
    iy = 0;
}