#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;

float *A;
int lda = 4096;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * N * lda);
    X = (float*)aligned_alloc(32, sizeof(float) * (N * abs(incX)));
    
    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (float)(idx % 100) / 10.0f;
    }
    for (int idx = 0; idx < N * abs(incX); idx++) {
        X[idx] = (float)(idx % 50) / 5.0f;
    }

    i = 0;
    j = 0;
    ix = 0;
}