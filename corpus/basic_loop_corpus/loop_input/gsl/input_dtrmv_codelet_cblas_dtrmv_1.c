#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

double *A;
int lda;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    // Allocate A as a square matrix of size N x N, row-major order
    lda = N;
    A = (double*)aligned_alloc(32, sizeof(double) * N * N);
    
    // Allocate X vector of size N
    X = (double*)aligned_alloc(32, sizeof(double) * N);
    
    // Initialize scalar parameters
    incX = 1;
    nonunit = 1;
    ix = (N - 1) * incX;  // starting index for backward traversal
    
    // Initialize arrays with predictable values to avoid NaN/inf and allow optimization
    for (int idx = 0; idx < N * N; idx++) {
        A[idx] = (double)(idx % 127) / 128.0;
    }
    
    for (int idx = 0; idx < N; idx++) {
        X[idx] = (double)(idx % 64) / 64.0;
    }
}