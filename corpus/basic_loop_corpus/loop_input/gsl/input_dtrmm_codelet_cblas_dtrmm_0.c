#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;

int n1 = 800;
int n2 = 600;
int lda = 800;
int ldb = 600;
int nonunit = 1;
int i, j, k;

double *A;
double *B;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * lda * n1);
    B = (double*)aligned_alloc(32, sizeof(double) * ldb * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (double)(idx % 127) / 43.0;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (double)(idx % 113) / 53.0;
    }
}