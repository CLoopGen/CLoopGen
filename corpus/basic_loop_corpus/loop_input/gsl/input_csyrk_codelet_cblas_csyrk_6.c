#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 512;
int lda = 512;
int ldc = 512;
void *A;
void *C;
int i, j, k;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void init_vars() {
    A = aligned_alloc(32, 2 * N * K * sizeof(float));
    C = aligned_alloc(32, 2 * N * N * sizeof(float));

    float *A_float = (float *)A;
    float *C_float = (float *)C;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_float[idx] = (float)(idx % 128) * 0.01f;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_float[idx] = (float)(idx % 64) * 0.02f;
    }
}