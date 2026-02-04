#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int N = 512;
int K = 256;
int lda = 512;
int ldc = 512;
int i, j, k;
double alpha_real = 1.5;
double alpha_imag = 0.8;

void* A = NULL;
void* C = NULL;

void init_vars() {
    A = aligned_alloc(32, sizeof(double) * 2 * K * lda);
    C = aligned_alloc(32, sizeof(double) * 2 * N * ldc);

    if (!A || !C) {
        exit(1);
    }

    memset(A, 0, sizeof(double) * 2 * K * lda);
    memset(C, 0, sizeof(double) * 2 * N * ldc);

    double* A_ptr = (double*)A;
    double* C_ptr = (double*)C;

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_ptr[idx] = (double)(idx % 128) / 64.0;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_ptr[idx] = (double)(idx % 256) / 128.0;
    }
}