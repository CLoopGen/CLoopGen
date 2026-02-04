#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
float alpha_real = 0.8f;
float alpha_imag = 0.6f;
int lda = 256;
int ldb = 256;
int ldc = 512;
int i, j, k;

float *A_data;
float *B_data;
float *C_data;

void *A = NULL;
void *B = NULL;
void *C = NULL;

void init_vars() {
    A_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * K);
    B_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * K);
    C_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * N);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (float)(idx % 128) / 128.0f;
        B_data[idx] = (float)((idx + 17) % 128) / 128.0f;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = (float)(idx % 256) / 256.0f;
    }
}