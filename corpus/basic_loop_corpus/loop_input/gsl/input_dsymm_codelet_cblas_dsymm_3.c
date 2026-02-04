#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

double alpha;
double *A;
int lda;
double *B;
int ldb;
double *C;
int ldc;
int i;
int j;
int k;
int n1;
int n2;

void init_vars() {
    n1 = 512;
    n2 = 512;
    lda = n1;
    ldb = n1;
    ldc = n1;
    alpha = 1.5;

    A = (double*)aligned_alloc(32, sizeof(double) * lda * n1);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n2);
    C = (double*)aligned_alloc(32, sizeof(double) * ldc * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < ldc * n2; idx++) {
        C[idx] = (double)(idx % 127) / 127.0;
    }
}