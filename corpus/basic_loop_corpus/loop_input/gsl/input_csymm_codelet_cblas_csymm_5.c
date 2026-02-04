#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

static float *A_data;
static float *B_data;
static float *C_data;

void *A;
void *B;
void *C;
int lda;
int ldb;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
float alpha_real;
float alpha_imag;

void init_vars() {
    n1 = 512;
    n2 = 512;
    lda = n2;
    ldb = n1;
    ldc = n2;
    alpha_real = 1.0f;
    alpha_imag = 0.5f;

    A_data = (float*)aligned_alloc(32, sizeof(float) * 2 * lda * n2);
    B_data = (float*)aligned_alloc(32, sizeof(float) * 2 * ldb * n1);
    C_data = (float*)aligned_alloc(32, sizeof(float) * 2 * ldc * n1);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * lda * n2; idx++) {
        A_data[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }
    for (int idx = 0; idx < 2 * ldb * n1; idx++) {
        B_data[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        C_data[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }
}