#include <stdio.h>
#include <inttypes.h>

int n = 1024;
double alpha = 1.5;
double beta = 0.5;
double A[1300][1300];
double B[1300][1300];
double tmp[1300];
double x[1300];
double y[1300];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < n; ii++) {
        x[ii] = 1.0 + ii * 0.001;
        y[ii] = 0.0;
        tmp[ii] = 0.0;
        for (int jj = 0; jj < n; jj++) {
            A[ii][jj] = (ii == jj) ? 2.0 : 0.1;
            B[ii][jj] = (ii == jj) ? 1.0 : -0.1;
        }
    }
}