#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
float alpha = 1.5f;

float *A_data;
void *A;
int lda = 256;

float *C_data;
void *C;
int ldc = 512;

int i, j, k;

void init_vars() {
    A_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * lda);
    C_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * ldc);
    A = (void*)A_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * N * lda; idx++) {
        A_data[idx] = (float)(idx % 128) / 64.0f;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = (float)(idx % 256) / 128.0f;
    }

    i = 0;
    j = 0;
    k = 0;
}