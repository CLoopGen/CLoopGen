#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 1024;
int K = 512;
double alpha = 1.5;

double *A;
int lda;
double *C;
int ldc;

int i, j, k;

void init_vars() {
    lda = K;
    ldc = N;

    A = (double*)aligned_alloc(32, sizeof(double) * N * lda);
    C = (double*)aligned_alloc(32, sizeof(double) * N * ldc);

    for (int idx = 0; idx < N * K; idx++) {
        A[idx] = (double)(rand() % 1000) / 100.0;
    }

    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = (double)(rand() % 1000) / 100.0;
    }
}