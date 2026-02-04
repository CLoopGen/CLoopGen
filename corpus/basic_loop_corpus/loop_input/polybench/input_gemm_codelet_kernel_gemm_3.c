#include <stdio.h>
#include <inttypes.h>

int ni = 500;
int nj = 400;
int nk = 600;
double alpha = 1.5;
double beta = 2.0;

double C[1000][1100];
double A[1000][1200];
double B[1200][1100];

int i, j, k;

void init_vars() {
    for (int ii = 0; ii < ni; ii++) {
        for (int jj = 0; jj < nj; jj++) {
            C[ii][jj] = (double)(ii + jj) / 100.0;
        }
    }

    for (int ii = 0; ii < ni; ii++) {
        for (int kk = 0; kk < nk; kk++) {
            A[ii][kk] = (double)(ii * kk + 1) / 7.0;
        }
    }

    for (int kk = 0; kk < nk; kk++) {
        for (int jj = 0; jj < nj; jj++) {
            B[kk][jj] = (double)(kk + jj + 2) / 13.0;
        }
    }
}