#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
double alpha = 1.5;

int lda = 256;
int ldb = 256;
int ldc = 512;

double *A;
double *B;
double *C;

int i, j, k;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * K);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * K);
    C = (double*)aligned_alloc(32, sizeof(double) * ldc * N);

    for (int idx = 0; idx < lda * K; idx++) {
        A[idx] = (double)(idx % 100) / 100.0;
    }
    for (int idx = 0; idx < ldb * K; idx++) {
        B[idx] = (double)(idx % 90 + 10) / 100.0;
    }
    for (int idx = 0; idx < ldc * N; idx++) {
        C[idx] = (double)(idx % 80 + 20) / 100.0;
    }
}