#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.2;

int n1 = 512;
int n2 = 512;
int nonunit = 1;
int i, j, k;
int lda = 512;
int ldb = 512;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(64, sizeof(double) * lda * n2);
    B = (double*)aligned_alloc(64, sizeof(double) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (double)(idx % 123) / 123.0;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (double)(idx % 179) / 179.0;
    }
    alpha = 1.5;
}