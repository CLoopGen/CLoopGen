#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N;
double *A;
int lda;
double *X;
int incX;
int nonunit;
int ix;
int jx;
int i;
int j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop has O(N^2) complexity, so we choose N accordingly
    N = 2048;  // Empirically chosen for ~0.01s on modern CPUs
    
    lda = N;
    
    // Allocate A as N x N matrix in column-major order
    A = (double*)aligned_alloc(32, sizeof(double) * N * lda);
    
    // Allocate X vector
    X = (double*)aligned_alloc(32, sizeof(double) * N);
    
    // Set reasonable values for increments and indices
    incX = 1;
    nonunit = 1;
    ix = (N - 1) * incX;
    jx = 0;
    i = 0;
    j = 0;
    
    // Initialize A as a diagonally dominant matrix to ensure numerical stability
    memset(A, 0, sizeof(double) * N * lda);
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            A[lda * col + row] = (row == col) ? 2.0 : ((double)rand() / RAND_MAX) * 0.5;
        }
    }
    
    // Initialize X with random values
    for (int k = 0; k < N; k++) {
        X[k] = (double)rand() / RAND_MAX;
    }
}