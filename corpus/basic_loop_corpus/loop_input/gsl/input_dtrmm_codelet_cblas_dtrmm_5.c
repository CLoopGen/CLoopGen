#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;
int n1 = 2048;
int n2 = 256;
int lda = 256;
int ldb = 2048;
int nonunit = 1;
int i, j, k;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * n2);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (double)(idx % 127) / 64.0;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (double)(idx % 131) / 67.0;
    }
}