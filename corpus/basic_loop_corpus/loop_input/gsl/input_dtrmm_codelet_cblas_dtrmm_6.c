#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha;
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
    n1 = 512;
    n2 = 512;
    lda = n2;
    ldb = n2;
    alpha = 1.5;
    nonunit = 1;

    size_t A_size = (size_t)lda * n2 * sizeof(double);
    size_t B_size = (size_t)ldb * n1 * sizeof(double);

    A = (double*)malloc(A_size);
    B = (double*)malloc(B_size);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (double)(idx % 127) / 10.0;
    }

    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (double)(idx % 131) / 10.0;
    }
}