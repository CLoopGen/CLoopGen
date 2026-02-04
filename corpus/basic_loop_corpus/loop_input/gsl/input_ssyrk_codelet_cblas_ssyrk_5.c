#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 256;
float alpha = 1.5f;

float *A;
int lda = 256;
float *C;
int ldc = 512;

int i, j, k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * K);
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * N);

    for (int idx = 0; idx < lda * K; idx++) {
        A[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }

    for (int idx = 0; idx < ldc * N; idx++) {
        C[idx] = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
}