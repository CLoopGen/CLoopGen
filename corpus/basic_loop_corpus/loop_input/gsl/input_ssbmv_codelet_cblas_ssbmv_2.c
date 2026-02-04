#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
int K = 64;
float alpha = 1.23f;

float *A;
int lda;

float *X;
int incX;

float *Y;
int incY;

int i;
int j;
int ix;
int iy;

void init_vars() {
    // Set array strides
    incX = 1;
    incY = 1;
    lda = N;  // leading dimension of A

    // Allocate matrices and vectors
    A = (float*)aligned_alloc(64, sizeof(float) * lda * N);
    X = (float*)aligned_alloc(64, sizeof(float) * N);
    Y = (float*)aligned_alloc(64, sizeof(float) * N);

    // Initialize data to avoid NaNs and infinities
    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 0.1f + idx * 0.01f;
        Y[idx] = -0.5f + idx * 0.02f;
    }

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            float val = (row == col) ? 2.0f : ((col > row && col < row + K + 1) ? 0.5f / (col - row + 1) : 0.0f);
            A[col - row + row * lda] = val;
        }
    }

    // Ensure indices start correctly based on strides
    ix = (incX >= 0) ? 0 : (N - 1) * (-incX);
    iy = (incY >= 0) ? 0 : (N - 1) * (-incY);
}