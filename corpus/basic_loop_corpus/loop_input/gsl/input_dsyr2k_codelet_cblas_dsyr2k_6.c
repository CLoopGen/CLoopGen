#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 1024;
int K = 128;
double alpha = 1.5;

int lda = 128;
int ldb = 128;
int ldc = 1024;

double *A;
double *B;
double *C;

int i;
int j;
int k;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * N * lda);
    B = (double*)aligned_alloc(32, sizeof(double) * N * ldb);
    C = (double*)aligned_alloc(32, sizeof(double) * N * ldc);

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (double)(idx % 127) * 0.01;
    }
    for (int idx = 0; idx < N * ldb; idx++) {
        B[idx] = (double)(idx % 131) * 0.01;
    }
    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (double)(idx % 137) * 0.02;
    }
}