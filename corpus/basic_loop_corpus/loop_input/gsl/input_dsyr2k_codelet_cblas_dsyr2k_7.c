#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 64;
double alpha = 1.7;

static double *A_data;
static double *B_data;
static double *C_data;

double *A;
int lda;
double *B;
int ldb;
double *C;
int i;
int j;
int k;

void init_vars() {
    lda = N;
    ldb = N;

    A_data = (double*)aligned_alloc(32, sizeof(double) * K * lda);
    B_data = (double*)aligned_alloc(32, sizeof(double) * K * ldb);
    C_data = (double*)aligned_alloc(32, sizeof(double) * N * N);

    A = A_data;
    B = B_data;
    C = C_data;

    for (int idx = 0; idx < K * lda; idx++) {
        A_data[idx] = (double)(idx % 128) / 64.0;
    }
    for (int idx = 0; idx < K * ldb; idx++) {
        B_data[idx] = (double)(idx % 128) / 64.0;
    }
    for (int idx = 0; idx < N * N; idx++) {
        C_data[idx] = 0.0;
    }
}