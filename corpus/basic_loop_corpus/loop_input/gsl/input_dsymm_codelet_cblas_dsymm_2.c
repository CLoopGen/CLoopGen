#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

double alpha = 1.5;
int lda = 1024;
int ldb = 1024;
int ldc = 1024;
int n1 = 1024;
int n2 = 1024;

double *A;
double *B;
double *C;

int i, j, k;

void init_vars() {
    const size_t size_a = (size_t)lda * n1;
    const size_t size_b = (size_t)ldb * n1;
    const size_t size_c = (size_t)ldc * n1;

    A = (double*)calloc(size_a, sizeof(double));
    B = (double*)calloc(size_b, sizeof(double));
    C = (double*)calloc(size_c, sizeof(double));

    for (size_t idx = 0; idx < size_a; idx++) {
        A[idx] = (double)(idx % 128) / 64.0;
    }
    for (size_t idx = 0; idx < size_b; idx++) {
        B[idx] = (double)(idx % 64) / 32.0;
    }
    for (size_t idx = 0; idx < size_c; idx++) {
        C[idx] = (double)(idx % 32) / 16.0;
    }

    alpha = 1.5;
    lda = 1024;
    ldb = 1024;
    ldc = 1024;
    n1 = 1024;
    n2 = 1024;
}