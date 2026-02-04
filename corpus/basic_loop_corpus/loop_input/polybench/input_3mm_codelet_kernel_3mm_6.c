#include <stdio.h>
#include <inttypes.h>

int ni = 800;
int nj = 900;
int nl = 1100;

double E[800][900];
double F[900][1100];
double G[800][1100];

int i, j, k;

void init_vars() {
    for (int ii = 0; ii < 800; ++ii) {
        for (int jj = 0; jj < 900; ++jj) {
            E[ii][jj] = (double)(ii + jj) / 800.0;
        }
    }
    for (int ii = 0; ii < 900; ++ii) {
        for (int jj = 0; jj < 1100; ++jj) {
            F[ii][jj] = (double)(ii * jj % 17) / 17.0;
        }
    }
    for (int ii = 0; ii < 800; ++ii) {
        for (int jj = 0; jj < 1100; ++jj) {
            G[ii][jj] = 0.0;
        }
    }
}