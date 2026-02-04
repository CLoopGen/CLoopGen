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
    // Set practical values for parameters
    incX = 1;
    nonunit = 1;
    
    // Allocate matrices with sufficient size to avoid out-of-bounds access
    // A is an N x N matrix in column-major layout, so we need N*N elements
    A = (float*)aligned_alloc(32, N * N * sizeof(float));
    X = (float*)aligned_alloc(32, N * sizeof(float));
    
    // Initialize all matrix and vector elements to prevent undefined behavior
    for (int idx = 0; idx < N * N; idx++) {
        A[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
    
    // Ensure diagonal dominance for numerical stability if nonunit
    for (int k = 0; k < N; k++) {
        float sum = 0.0f;
        for (int kk = 0; kk < N; kk++) {
            sum += fabsf(A[k + kk * lda]);
        }
        A[k + k * lda] = sum + 1.0f; // dominant diagonal
    }
    
    // Set initial index values to traverse from end of vector
    ix = (N - 1) * incX;
    jx = 0; // will be computed inside loop
}