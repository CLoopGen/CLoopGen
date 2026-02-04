#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;

float *A_data;
float *B_data;
float *C_data;

void *A = NULL;
void *B = NULL;
void *C = NULL;

int lda = 256;
int ldb = 256;
int ldc = 512;

int i = 0;
int j = 0;
int k = 0;

float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void init_vars() {
    const size_t A_size = (size_t)N * lda * 2;
    const size_t B_size = (size_t)N * ldb * 2;
    const size_t C_size = (size_t)N * ldc * 2;

    A_data = (float*)aligned_alloc(32, A_size * sizeof(float));
    B_data = (float*)aligned_alloc(32, B_size * sizeof(float));
    C_data = (float*)aligned_alloc(32, C_size * sizeof(float));

    for (size_t idx = 0; idx < A_size; idx++) {
        A_data[idx] = (float)((idx % 100) - 50) / 100.0f;
    }
    for (size_t idx = 0; idx < B_size; idx++) {
        B_data[idx] = (float)((idx % 100) - 40) / 100.0f;
    }
    for (size_t idx = 0; idx < C_size; idx++) {
        C_data[idx] = (float)((idx % 100) - 45) / 100.0f;
    }

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    i = 0;
    j = 0;
    k = 0;
}