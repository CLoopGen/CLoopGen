#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double *X;
int incX;
double *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    N = 10000000;  // 10M elements, roughly 80MB total for X and Y (assuming double is 8 bytes)

    incX = 1;
    incY = 1;

    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));

    if (!X || !Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = 1.0 + j * 0.1;
        Y[j] = 2.0 + j * 0.2;
    }

    ix = 0;
    iy = 0;
}