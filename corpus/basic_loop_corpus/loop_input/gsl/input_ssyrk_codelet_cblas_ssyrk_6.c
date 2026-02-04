#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 1024;
int K = 256;
float alpha = 1.5f;
float *A;
int lda = 256;
float *C;
int ldc = 1024;
int i;
int j;
int k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * N);
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * N);

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (float)(drand48() - 0.5) * 2.0f;
    }

    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (float)(drand48() - 0.5) * 2.0f;
    }
}