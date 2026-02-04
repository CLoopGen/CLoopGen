#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
double alpha = 1.5;
double *Ap = NULL;
double *X = NULL;
double *Y = NULL;
int incX = 1;
int incY = 1;
int i = 0;
int j = 0;
int ix = 0;
int iy = 0;

void init_vars() {
    const size_t ap_size = (N * (N + 1)) / 2;
    Ap = (double*)calloc(ap_size, sizeof(double));
    X = (double*)calloc(N, sizeof(double));
    Y = (double*)calloc(N, sizeof(double));

    for (int k = 0; k < N; ++k) {
        X[k] = 1.0 / (k + 1);
        Y[k] = 0.0;
    }

    for (size_t k = 0; k < ap_size; ++k) {
        Ap[k] = 0.1;
    }

    ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    iy = ((incY) > 0 ? 0 : (N - 1) * (-incY));
}