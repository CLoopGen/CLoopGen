#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

int N;
double *Ap;
double *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    N = 2048;
    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    size_t ap_size = (N * (N + 1)) / 2;
    Ap = (double*)calloc(ap_size, sizeof(double));
    if (!Ap) exit(1);

    X = (double*)malloc(N * sizeof(double));
    if (!X) exit(1);

    for (int k = 0; k < N; k++) {
        X[k] = 1.0;
    }

    for (size_t idx = 0; idx < ap_size; idx++) {
        Ap[idx] = 1.0;
    }
}