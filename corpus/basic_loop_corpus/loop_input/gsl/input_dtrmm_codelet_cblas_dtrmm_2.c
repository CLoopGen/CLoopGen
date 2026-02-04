#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;

int n1 = 200;
int n2 = 200;
int lda = 200;
int ldb = 200;
int nonunit = 1;
int i, j, k;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * n1);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (double)(idx % 123) / 123.0;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (double)(idx % 127) / 127.0;
    }
}