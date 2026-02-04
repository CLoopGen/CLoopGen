#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 4096;
float *Ap;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    // Allocate Ap as a packed lower triangular matrix: size N*(N+1)/2
    size_t ap_size = (size_t)N * (N + 1) / 2;
    Ap = (float*)aligned_alloc(32, ap_size * sizeof(float));
    
    // Allocate X vector
    X = (float*)aligned_alloc(32, N * sizeof(float));
    
    // Initialize all elements of Ap and X to avoid undefined behavior
    for (size_t k = 0; k < ap_size; k++) {
        Ap[k] = 1.0f + (k % 100) * 0.01f;
    }
    
    for (int k = 0; k < N; k++) {
        X[k] = (float)(k + 1) * 0.1f;
    }
    
    // Initialize loop indices
    i = N;
    ix = (incX > 0 ? N - 1 : 0);
}