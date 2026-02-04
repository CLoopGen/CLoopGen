#include <stdio.h>
#include <inttypes.h>

int m = 1200;
int n = 1400;
double float_n = 1400.0;

double data[1400][1200];
double cov[1200][1200];

int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            data[ii][jj] = (ii + jj) * 0.5;
        }
    }

    for (int ii = 0; ii < m; ii++) {
        for (int jj = 0; jj < m; jj++) {
            cov[ii][jj] = 0.0;
        }
    }

    i = 0;
    j = 0;
    k = 0;
}