#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define N1_DEFAULT 512
#define N2_DEFAULT 512

float *A_data;
float *B_data;
float *C_data;

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
    n1 = N1_DEFAULT;
    n2 = N2_DEFAULT;
    lda = n1;
    ldb = n1;
    ldc = n2;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    size_t A_size = 2 * lda * n2 * sizeof(float);
    size_t B_size = 2 * ldb * n1 * sizeof(float);
    size_t C_size = 2 * ldc * n1 * sizeof(float);

    A_data = (float*)aligned_alloc(32, A_size);
    B_data = (float*)aligned_alloc(32, B_size);
    C_data = (float*)aligned_alloc(32, C_size);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < 2 * lda * n2; idx++) {
        A_data[idx] = ((float)rand()) / RAND_MAX;
    }
    for (size_t idx = 0; idx < 2 * ldb * n1; idx++) {
        B_data[idx] = ((float)rand()) / RAND_MAX;
    }
    for (size_t idx = 0; idx < 2 * ldc * n1; idx++) {
        C_data[idx] = ((float)rand()) / RAND_MAX;
    }
}