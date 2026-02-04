#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1000;

double A[1900][2100];
double x[2100];
double y[2100];
double tmp[1900];

int i;
int j;

void init_vars() {
    for (int ii = 0; ii < m; ii++) {
        for (int jj = 0; jj < n; jj++) {
            A[ii][jj] = (double)(ii + jj) / 100.0;
        }
    }
    for (int jj = 0; jj < n; jj++) {
        x[jj] = 1.0;
        y[jj] = 0.0;
    }
}