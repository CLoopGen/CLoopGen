#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

float *A;
int lda = 2048;
float *X;
int incX = 1;
int nonunit = 1;
int ix;
int jx;
int i;
int j;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * N);
    X = (float*)aligned_alloc(32, sizeof(float) * (N * abs(incX)));
    
    for (int idx = 0; idx < N; idx++) {
        X[idx * incX] = 1.0f + 0.01f * idx;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            A[lda * row + col] = (row == col) ? 2.0f : ((col > row) ? 0.1f * (row + col) : 0.0f);
        }
    }

    ix = (N - 1) * incX;
}