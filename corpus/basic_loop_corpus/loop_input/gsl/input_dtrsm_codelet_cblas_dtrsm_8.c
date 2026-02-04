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
int n1;
int n2;
int nonunit;

static double A_data[2048 * 2048];
static double B_data[2048 * 2048];

void init_vars() {
    n1 = 2048;
    n2 = 2048;
    lda = n2;
    ldb = n2;
    nonunit = 1;

    A = A_data;
    B = B_data;

    for (int idx = 0; idx < n1 * n2; idx++) {
        A_data[idx] = 1.0 + (idx % 100) * 0.01;
        B_data[idx] = (idx % 17) * 0.1;
    }

    for (int jj = 0; jj < n2; jj++) {
        A_data[lda * jj + jj] = 2.0; 
    }
}