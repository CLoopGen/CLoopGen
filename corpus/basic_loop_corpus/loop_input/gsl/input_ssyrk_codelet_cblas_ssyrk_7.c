#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 1024;
float alpha = 1.5f;

float *A;
int lda = 1024;
float *C;
int ldc = 512;

int i, j, k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * (size_t)lda * (size_t)N);
    C = (float*)aligned_alloc(32, sizeof(float) * (size_t)ldc * (size_t)N);

    for (int idx = 0; idx < K * N; idx++) {
        A[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = (float)(idx % 200) / 200.0f;
    }
}