#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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

static double A_data[2048 * 2048];
static double B_data[2048 * 2048];

void init_vars() {
    n1 = 2048;
    n2 = 2048;
    lda = 2048;
    ldb = 2048;
    nonunit = 1;

    A = A_data;
    B = B_data;

    for (int idx = 0; idx < n1 * n2; idx++) {
        A[idx] = 1.0 + 0.01 * (idx % 127);
        B[idx] = (double)(idx % 1000) / 100.0;
    }

    for (int ii = 0; ii < n2; ii++) {
        A[lda * ii + ii] = 2.0; 
    }
}