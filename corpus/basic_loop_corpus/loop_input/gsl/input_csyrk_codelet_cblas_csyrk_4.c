#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
int lda = 256;
int ldc = 512;
int i, j, k;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void *A;
void *C;

void init_vars() {
    A = aligned_alloc(32, 2 * sizeof(float) * N * lda);
    C = aligned_alloc(32, 2 * sizeof(float) * N * ldc);

    if (!A || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    float *A_float = (float *)A;
    float *C_float = (float *)C;

    for (int idx = 0; idx < 2 * N * lda; idx++) {
        A_float[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_float[idx] = (float)(idx % 50) / 50.0f;
    }
}