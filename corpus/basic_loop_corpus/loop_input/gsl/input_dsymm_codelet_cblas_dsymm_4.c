#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

    lda = n2;
    ldb = n2;
    ldc = n2;

    alpha = 1.5;

    A = (double*)aligned_alloc(64, sizeof(double) * n2 * n2);
    B = (double*)aligned_alloc(64, sizeof(double) * n1 * n2);
    C = (double*)aligned_alloc(64, sizeof(double) * n1 * n2);

    for (int idx = 0; idx < n2 * n2; idx++) {
        A[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < n1 * n2; idx++) {
        B[idx] = (double)(idx % 131) / 131.0;
        C[idx] = (double)(idx % 137) / 137.0;
    }

    i = 0;
    j = 0;
    k = 0;
}