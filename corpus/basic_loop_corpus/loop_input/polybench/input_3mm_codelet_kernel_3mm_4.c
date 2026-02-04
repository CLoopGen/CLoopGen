#include <stdio.h>
#include <inttypes.h>

int ni = 800;
int nj = 900;
int nk = 1000;

double E[800][900];
double A[800][1000];
double B[1000][900];

int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < ni; ++ii) {
        for (int jj = 0; jj < nj; ++jj) {
            E[ii][jj] = 0.0;
        }
    }

    for (int ii = 0; ii < ni; ++ii) {
        for (int kk = 0; kk < nk; ++kk) {
            A[ii][kk] = (double)(ii + kk);
        }
    }

    for (int kk = 0; kk < nk; ++kk) {
        for (int jj = 0; jj < nj; ++jj) {
            B[kk][jj] = (double)(kk * jj + 1);
        }
    }
}