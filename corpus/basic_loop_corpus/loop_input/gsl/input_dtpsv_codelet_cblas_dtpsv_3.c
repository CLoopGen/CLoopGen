#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
double *Ap = NULL;
double *X = NULL;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    const size_t Ap_size = ((size_t)N * (N + 1)) / 2;
    Ap = (double*)aligned_alloc(32, Ap_size * sizeof(double));
    X = (double*)aligned_alloc(32, N * sizeof(double));

    for (size_t idx = 0; idx < Ap_size; idx++) {
        Ap[idx] = 1.0 + (idx % 7);
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx] = (double)(idx + 1);
    }

    i = N - 1;
    ix = (N - 1) * incX;
}