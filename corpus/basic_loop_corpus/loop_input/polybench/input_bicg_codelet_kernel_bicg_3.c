#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define N 2000
#define M 1800

int m = M;
int n = N;
double A[2100][1900];
double s[1900];
double q[2100];
double p[1900];
double r[2100];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < N; ii++) {
        r[ii] = 1.0 + ii * 0.001;
        q[ii] = 0.0;
        for (int jj = 0; jj < M; jj++) {
            if (ii < 2100 && jj < 1900) {
                A[ii][jj] = 1.0 / (2.0 + ii + jj);
            }
        }
    }
    for (int jj = 0; jj < M; jj++) {
        s[jj] = 0.0;
        p[jj] = 1.0 + jj * 0.002;
    }
}