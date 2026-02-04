#include <stdio.h>
#include <inttypes.h>

int n = 1000;

double A[2000][2000];

int i;
int j;
int k;

double w;

void init_vars() {
    for (int ii = 0; ii < 2000; ii++) {
        for (int jj = 0; jj < 2000; jj++) {
            A[ii][jj] = (ii == jj) ? 2.0 : 1.0 / (ii + jj + 1);
        }
    }

    for (int ii = 0; ii < n; ii++) {
        A[ii][ii] += 1.0;
    }

    i = 0;
    j = 0;
    k = 0;
    w = 0.0;
}