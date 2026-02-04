#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;
int n1 = 500;
int n2 = 500;
int nonunit = 1;
int lda = 500;
int ldb = 500;
int i, j, k;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * n2);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (double)(idx % 127) / 10.0;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (double)((idx + 1) % 131) / 11.0;
    }

    alpha = 1.5;
    n1 = 500;
    n2 = 500;
    lda = 500;
    ldb = 500;
    nonunit = 1;
}