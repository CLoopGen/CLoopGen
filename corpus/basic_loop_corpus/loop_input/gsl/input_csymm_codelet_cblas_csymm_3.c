#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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
    lda = n1;
    ldb = n1;
    ldc = n1;

    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    size_t A_size = 2 * lda * n1 * sizeof(float);
    size_t B_size = 2 * ldb * n2 * sizeof(float);
    size_t C_size = 2 * ldc * n2 * sizeof(float);

    A_data = (float *)aligned_alloc(32, A_size);
    B_data = (float *)aligned_alloc(32, B_size);
    C_data = (float *)aligned_alloc(32, C_size);

    A = (void *)A_data;
    B = (void *)B_data;
    C = (void *)C_data;

    for (size_t idx = 0; idx < 2 * lda * n1; idx++) {
        A_data[idx] = (rand() / (float)RAND_MAX) * 0.1f;
    }
    for (size_t idx = 0; idx < 2 * ldb * n2; idx++) {
        B_data[idx] = (rand() / (float)RAND_MAX) * 0.1f;
    }
    for (size_t idx = 0; idx < 2 * ldc * n2; idx++) {
        C_data[idx] = (rand() / (float)RAND_MAX) * 0.1f;
    }
}