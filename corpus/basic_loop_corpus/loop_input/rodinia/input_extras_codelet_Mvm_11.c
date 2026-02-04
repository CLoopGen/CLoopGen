#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int m = 1000;
int _usr_j0 = 0;
double alpha = 1.5;
double **A;
double *x;
double *y;
int i;
int j;
int m4;
int n2;
double *Aref0;
double *Aref1;
double tmp0;
double tmp1;
double yval0;
double yval1;
double yval2;
double yval3;

void init_vars() {
    n2 = 128;
    m4 = m / 4;

    x = (double*)aligned_alloc(32, sizeof(double) * 2 * n2);
    y = (double*)aligned_alloc(32, sizeof(double) * (4 * m4 + m) * n2);

    A = (double**)aligned_alloc(32, sizeof(double*) * (2 * n2));
    for (int idx = 0; idx < 2 * n2; idx++) {
        A[idx] = (double*)aligned_alloc(32, sizeof(double) * (m + 4 * m4));
    }

    for (int idx = 0; idx < 2 * n2; idx++) {
        for (int jdx = 0; jdx < m + 4 * m4; jdx++) {
            A[idx][jdx] = ((double)rand() / RAND_MAX);
        }
    }

    for (int idx = 0; idx < 2 * n2; idx++) {
        x[idx] = ((double)rand() / RAND_MAX);
    }

    for (int idx = 0; idx < (4 * m4 + m) * n2; idx++) {
        y[idx] = ((double)rand() / RAND_MAX);
    }
}