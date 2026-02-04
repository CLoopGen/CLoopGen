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
int n1 = 1024;
int n2 = 128;
int nonunit = 1;

void init_vars() {
    lda = n1;
    ldb = n2;

    A = (double*)calloc(lda * n1, sizeof(double));
    B = (double*)calloc(ldb * n1, sizeof(double));

    for (int ii = 0; ii < n1; ii++) {
        A[lda * ii + ii] = 2.0; 
        for (int jj = 0; jj < n2; jj++) {
            B[ldb * ii + jj] = 1.0;
        }
    }

    for (int ii = 0; ii < n1; ii++) {
        for (int kk = ii + 1; kk < n1; kk++) {
            A[kk * lda + ii] = 0.5;
        }
    }
}