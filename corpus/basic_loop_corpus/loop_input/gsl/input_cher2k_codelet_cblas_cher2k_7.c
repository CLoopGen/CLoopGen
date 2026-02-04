#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

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
    C_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * ldc);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (float)(idx % 128) * 1e-2f;
        B_data[idx] = (float)((idx * 7) % 128) * 1e-2f;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = (float)(idx % 64) * 1e-3f;
    }

    i = 0;
    j = 0;
    k = 0;
}