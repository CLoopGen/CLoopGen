#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
    Ap = (double*)aligned_alloc(32, ap_size * sizeof(double));
    X = (double*)aligned_alloc(32, N * sizeof(double));

    for (size_t idx = 0; idx < ap_size; idx++) {
        Ap[idx] = 1.0 + 0.01 * (idx % 127);
    }

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k + 1);
    }
}