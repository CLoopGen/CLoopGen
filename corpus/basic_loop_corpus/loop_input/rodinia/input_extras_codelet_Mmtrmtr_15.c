#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m = 200;
int n = 200;
int p = 200;
int Aj0 = 0;
int Bj0 = 0;
int Cj0 = 0;
int i, j, k;

double **A;
double **B;
double **C;

void init_vars() {
    A = (double**)calloc(m, sizeof(double*));
    B = (double**)calloc(p, sizeof(double*));
    C = (double**)calloc(m, sizeof(double*));

    for (int ii = 0; ii < m; ii++) {
        A[ii] = (double*)calloc(p, sizeof(double));
        C[ii] = (double*)calloc(n, sizeof(double));
    }

    for (int kk = 0; kk < p; kk++) {
        B[kk] = (double*)calloc(n, sizeof(double));
    }

    for (int ii = 0; ii < m; ii++) {
        for (int kk = 0; kk < p; kk++) {
            A[ii][Aj0 + kk] = 1.0 + ii + kk;
        }
    }

    for (int kk = 0; kk < p; kk++) {
        for (int jj = 0; jj < n; jj++) {
            B[kk][Bj0 + jj] = 1.0 + kk - jj;
        }
    }

    for (int ii = 0; ii < m; ii++) {
        for (int jj = 0; jj < n; jj++) {
            C[ii][Cj0 + jj] = 0.0;
        }
    }
}