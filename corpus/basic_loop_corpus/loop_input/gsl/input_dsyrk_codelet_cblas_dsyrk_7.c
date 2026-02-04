#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int K = 128;
double alpha = 1.5;

double *A;
int lda = 1024;
double *C;
int ldc = 1024;

int i, j, k;

void init_vars() {
    A = (double*)malloc(sizeof(double) * K * lda);
    C = (double*)malloc(sizeof(double) * N * ldc);

    for (int idx = 0; idx < K * lda; idx++) {
        A[idx] = (double)(idx % 127) / 10.0;
    }

    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (double)(idx % 251) / 10.0;
    }
}