#include <stdio.h>
#include <inttypes.h>

int n = 1024;

double A[2000][2000];
double x[2000];
double y[2000];
int i;
int j;
double w;

void init_vars() {
    for (int ii = 0; ii < n; ii++) {
        y[ii] = 1.0 * ii;
        x[ii] = 0.0;
        for (int jj = 0; jj < n; jj++) {
            A[ii][jj] = (ii == jj) ? 2.0 : 0.1;
        }
    }
}