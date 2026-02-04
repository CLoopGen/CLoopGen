#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

void *A = NULL;
int lda;
void *B = NULL;
int ldb;
void *C = NULL;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
float alpha_real;
float alpha_imag;

static float *A_data = NULL;
static float *B_data = NULL;
static float *C_data = NULL;

void init_vars() {
    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    n1 = 1024;
    n2 = 512;

    lda = n2;
    ldb = n1;
    ldc = n2;

    size_t A_size = 2 * lda * n2 * sizeof(float);
    size_t B_size = 2 * ldb * n1 * sizeof(float);
    size_t C_size = 2 * ldc * n1 * sizeof(float);

    A_data = (float *)aligned_alloc(32, A_size);
    B_data = (float *)aligned_alloc(32, B_size);
    C_data = (float *)aligned_alloc(32, C_size);

    A = (void *)A_data;
    B = (void *)B_data;
    C = (void *)C_data;

    for (size_t idx = 0; idx < A_size / sizeof(float); idx++) {
        A_data[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < B_size / sizeof(float); idx++) {
        B_data[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < C_size / sizeof(float); idx++) {
        C_data[idx] = (float)(idx % 50) / 50.0f;
    }
}