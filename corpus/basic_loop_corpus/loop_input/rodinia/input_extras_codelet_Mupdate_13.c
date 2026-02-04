#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m = 2000;
int n = 128;
int _usr_j0 = 0;
double alpha = 1.5;
double **A;
double *x;
double *y;
int i;
int j;
int n4;
double *Aref;
double tmp;

void init_vars() {
    n4 = n / 4;

    x = (double*)aligned_alloc(32, m * sizeof(double));
    y = (double*)aligned_alloc(32, (n + 4 * n4) * sizeof(double));

    A = (double**)aligned_alloc(32, m * sizeof(double*));
    for (i = 0; i < m; i++) {
        A[i] = (double*)aligned_alloc(32, (n + 4 * n4) * sizeof(double));
    }

    for (i = 0; i < m; i++) {
        x[i] = 1.0 + i * 0.1;
        for (j = 0; j < n + 4 * n4; j++) {
            A[i][j] = 0.0;
        }
    }

    for (j = 0; j < n + 4 * n4; j++) {
        y[j] = 2.0 + j * 0.01;
    }

    Aref = NULL;
    tmp = 0.0;
}