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
    // Allocate A as a 2D matrix of size at least N x N in column-major layout
    lda = N; // leading dimension
    A = (float*)aligned_alloc(32, sizeof(float) * lda * N);
    
    // Allocate X vector with enough elements based on access pattern
    // The loop accesses X[ix], and ix decreases from (N-1)*|incX| down
    incX = 1; // choose positive stride for simplicity
    int x_size = N * abs(incX); // sufficient size
    X = (float*)aligned_alloc(32, sizeof(float) * x_size);

    // Initialize all values to prevent NaN or extreme values affecting timing
    for (int k = 0; k < N * N; k++) {
        A[k] = 1.0f / (k + 1); // small decreasing values
    }
    for (int k = 0; k < x_size; k++) {
        X[k] = 1.0f;
    }

    // Set loop counters and flags
    i = N; // will be decremented in loop condition
    nonunit = 1; // enable the diagonal scaling
    ix = (N - 1) * incX; // initial index into X, matches access pattern

    // Ensure no out-of-bounds: inner loop uses j < i and A[lda*j + i], so i < N is safe
    // With N=2048, total operations ~ O(N^2), which should take ~0.01s on modern CPU
}