#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 256;
int K = 128;
int lda = 256;
int ldb = 256;
float alpha_real = 1.5f;
float alpha_imag = 0.5f;
int i, j, k;

void* A;
void* B;
void* C;

void init_vars() {
    A = aligned_alloc(32, 2 * sizeof(float) * K * lda);
    B = aligned_alloc(32, 2 * sizeof(float) * K * ldb);
    C = aligned_alloc(32, 2 * sizeof(float) * N * lda);

    float* A_float = (float*)A;
    float* B_float = (float*)B;
    float* C_float = (float*)C;

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_float[idx] = (float)(idx % 100) / 100.0f;
    }
    for (int idx = 0; idx < 2 * K * ldb; idx++) {
        B_float[idx] = (float)(idx % 90) / 90.0f;
    }
    for (int idx = 0; idx < 2 * N * lda; idx++) {
        C_float[idx] = 0.0f;
    }
}