#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;

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
    lda = N;
    incX = 1;
    nonunit = 1;
    ix = 0;
    jx = 0;

    A = (float*)aligned_alloc(32, sizeof(float) * N * N);
    X = (float*)aligned_alloc(32, sizeof(float) * N);

    for (int idx = 0; idx < N; idx++) {
        X[idx] = 1.0f;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col <= row; col++) {
            A[lda * row + col] = (row == col) ? 2.0f : 1.0f;
        }
    }
}