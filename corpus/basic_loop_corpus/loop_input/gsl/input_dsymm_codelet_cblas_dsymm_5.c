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
    n1 = 400;
    n2 = 400;
    lda = n2;
    ldb = n1;
    ldc = n2;

    alpha = 1.5;

    A = (double*)aligned_alloc(32, sizeof(double) * lda * n2);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n2);
    C = (double*)aligned_alloc(32, sizeof(double) * ldc * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (double)(idx % 123) / 123.0;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (double)(idx % 149) / 149.0;
    }
    for (int idx = 0; idx < ldc * n1; idx++) {
        C[idx] = (double)(idx % 167) / 167.0;
    }
}