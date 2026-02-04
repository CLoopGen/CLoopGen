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
int n1 = 256;
int n2 = 256;
float alpha_real = 1.5f;
float alpha_imag = 0.8f;

void init_vars() {
    const size_t alignment = 32;
    const size_t elem_size = sizeof(float);
    
    lda = n1;
    ldb = n1;
    ldc = n2;

    posix_memalign(&A, alignment, n1 * lda * 2 * elem_size);
    posix_memalign(&B, alignment, n1 * n2 * 2 * elem_size);
    posix_memalign(&C, alignment, n1 * n2 * 2 * elem_size);

    float *A_float = (float *)A;
    float *B_float = (float *)B;
    float *C_float = (float *)C;

    for (int idx = 0; idx < n1 * lda * 2; idx++) {
        A_float[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }

    for (int idx = 0; idx < n1 * n2 * 2; idx++) {
        B_float[idx] = (float)(idx % 256) / 128.0f - 1.0f;
    }

    for (int idx = 0; idx < n1 * n2 * 2; idx++) {
        C_float[idx] = (float)(idx % 64) / 32.0f - 1.0f;
    }
}