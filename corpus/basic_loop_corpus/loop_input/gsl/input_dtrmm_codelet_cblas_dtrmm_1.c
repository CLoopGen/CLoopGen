#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;

int n1 = 400;
int n2 = 300;
int nonunit = 1;
int i, j, k;
int lda = 400;
int ldb = 300;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(64, sizeof(double) * lda * n1);
    B = (double*)aligned_alloc(64, sizeof(double) * ldb * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (double)(idx % 127) / 128.0;
    }
}