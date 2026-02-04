#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime

double *X;
int incX = 1;
double *Y;
int incY = 1;
double r = 0.0;
int i;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));

    for (int j = 0; j < N; j++) {
        X[j] = (double)(j % 127) + 1.0;
        Y[j] = (double)((j * 7) % 131) + 1.0;
    }
}