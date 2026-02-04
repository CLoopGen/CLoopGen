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

static double A_data[4096];
static double B_data[8192];

void init_vars() {
    n1 = 64;
    n2 = 64;
    lda = 64;
    ldb = 64;
    nonunit = 1;

    A = A_data;
    B = B_data;

    for (int idx = 0; idx < 4096; idx++) {
        A_data[idx] = 1.0 + 0.01 * (idx % 128);
    }

    for (int idx = 0; idx < 8192; idx++) {
        B_data[idx] = 0.1 * (idx % 256);
    }
}