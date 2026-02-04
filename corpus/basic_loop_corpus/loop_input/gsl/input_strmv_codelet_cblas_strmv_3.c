#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;

float *A;
int lda;
float *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    lda = N;
    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    A = (float*)aligned_alloc(32, sizeof(float) * N * lda);
    X = (float*)aligned_alloc(32, sizeof(float) * (N + (N-1) * abs(incX)));

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (float)(rand() % 100) / 50.0f;
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx * abs(incX)] = (float)(rand() % 100) / 50.0f;
    }
}