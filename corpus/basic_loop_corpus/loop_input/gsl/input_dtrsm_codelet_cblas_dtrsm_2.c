#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *A;
int lda;
double *B;
int ldb;
int i;
int j;
int k;
int n1;
int n2;
int nonunit;

void init_vars() {
    n1 = 1024;
    n2 = 512;
    lda = n1;
    ldb = n2;
    nonunit = 1;

    A = (double*)aligned_alloc(64, sizeof(double) * lda * n1);
    B = (double*)aligned_alloc(64, sizeof(double) * ldb * n1);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = 1.0 + (idx % 7) * 0.1;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (idx % 13) * 0.5;
    }
}