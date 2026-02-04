#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;
int n1 = 512;
int n2 = 512;
int lda = 512;
int ldb = 512;
int nonunit = 1;
int i, j, k;

double *A = NULL;
double *B = NULL;

void init_vars() {
    A = (double*)calloc(n1 * lda, sizeof(double));
    B = (double*)calloc(n2 * ldb, sizeof(double));

    if (!A || !B) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < n1 * lda; idx++) {
        A[idx] = 1.0 + (idx % 17) * 0.1;
    }
    for (int idx = 0; idx < n2 * ldb; idx++) {
        B[idx] = 2.0 + (idx % 19) * 0.1;
    }

    for (int ii = 0; ii < n1; ii++) {
        A[ii * lda + ii] = 2.0;
    }
}