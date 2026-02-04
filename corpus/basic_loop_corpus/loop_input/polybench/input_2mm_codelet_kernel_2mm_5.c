#include <stdio.h>
#include <inttypes.h>

int ni = 800;
int nj = 900;
int nl = 1200;
double beta = 1.5;

double tmp[800][900];
double C[900][1200];
double D[800][1200];

int i, j, k;

void init_vars() {
    for (int ii = 0; ii < 800; ++ii) {
        for (int jj = 0; jj < 900; ++jj) {
            tmp[ii][jj] = (double)(ii + jj) / 800.0;
        }
    }

    for (int ii = 0; ii < 900; ++ii) {
        for (int jj = 0; jj < 1200; ++jj) {
            C[ii][jj] = (double)(ii * jj + 1) / 1000.0;
        }
    }

    for (int ii = 0; ii < 800; ++ii) {
        for (int jj = 0; jj < 1200; ++jj) {
            D[ii][jj] = (double)(ii + jj) / 500.0;
        }
    }

    ni = 800;
    nj = 900;
    nl = 1200;
    beta = 1.5;
}