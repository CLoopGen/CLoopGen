#include <stdio.h>
#include <inttypes.h>

int nj = 800;
int nl = 1000;
int nm = 900;

double F[900][1100];
double C[900][1200];
double D[1200][1100];

int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < nj; ++ii) {
        for (int jj = 0; jj < nl; ++jj) {
            F[ii][jj] = 0.0;
        }
    }

    for (int ii = 0; ii < nj; ++ii) {
        for (int kk = 0; kk < nm; ++kk) {
            C[ii][kk] = (double)(ii % 100 + kk % 50) / 100.0;
        }
    }

    for (int kk = 0; kk < nm; ++kk) {
        for (int jj = 0; jj < nl; ++jj) {
            D[kk][jj] = (double)(kk % 75 + jj % 25) / 100.0;
        }
    }
}