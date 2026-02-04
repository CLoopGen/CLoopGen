#include <stdio.h>
#include <inttypes.h>

int n = 1000;

double A[2000][2000];
double u1[2000];
double v1[2000];
double u2[2000];
double v2[2000];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 2000; ii++) {
        u1[ii] = 1.0 + ii * 0.001;
        v1[ii] = 1.5 + ii * 0.002;
        u2[ii] = 2.0 + ii * 0.001;
        v2[ii] = 2.5 + ii * 0.002;
        for (int jj = 0; jj < 2000; jj++) {
            A[ii][jj] = (ii == jj) ? 1.0 : 0.0;
        }
    }
}