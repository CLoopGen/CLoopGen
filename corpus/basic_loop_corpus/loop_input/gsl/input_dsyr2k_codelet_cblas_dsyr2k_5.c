#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int N = 512;
int K = 64;
double alpha = 1.5;

double *A;
int lda = 512;
double *B;
int ldb = 512;
double *C;
int i, j, k;

void init_vars() {
    A = (double*)aligned_alloc(32, (size_t)K * lda * sizeof(double));
    B = (double*)aligned_alloc(32, (size_t)K * ldb * sizeof(double));
    C = (double*)aligned_alloc(32, (size_t)N * N * sizeof(double));

    for (int idx = 0; idx < K * lda; idx++) {
        A[idx] = (double)(idx % 17) * 0.1;
    }
    for (int idx = 0; idx < K * ldb; idx++) {
        B[idx] = (double)(idx % 19) * 0.1;
    }
    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = (double)(idx % 23) * 0.05;
    }
}