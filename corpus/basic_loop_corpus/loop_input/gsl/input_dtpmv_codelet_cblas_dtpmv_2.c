#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

double *Ap;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    Ap = (double*)calloc((N * (N + 1)) / 2, sizeof(double));
    X = (double*)calloc(N, sizeof(double));
    ix = N - 1;

    for (int k = 0; k < (N * (N + 1)) / 2; ++k) {
        Ap[k] = 1.0;
    }
    for (int k = 0; k < N; ++k) {
        X[k] = 1.0;
    }
}