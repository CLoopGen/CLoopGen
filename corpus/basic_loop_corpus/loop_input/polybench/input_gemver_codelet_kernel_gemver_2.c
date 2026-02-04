#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double beta = 1.5;
double A[2000][2000];
double x[2000];
double y[2000];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < n; ii++) {
        x[ii] = 1.0 + ii * 0.1;
        y[ii] = 2.0 - ii * 0.05;
        for (int jj = 0; jj < n; jj++) {
            A[jj][ii] = (ii == jj) ? 2.0 : ((ii == jj+1 || ii == jj-1) ? -1.0 : 0.01);
        }
    }
}