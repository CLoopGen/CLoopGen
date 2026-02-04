#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 1 << 20; // 1 million elements for ~0.01 sec runtime
double *X;
int incX = 1;
double *Y;
int incY = 1;
double c = 0.86602540378; // cos(30°)
double s = 0.5;          // sin(30°)
int i;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (double*)aligned_alloc(32, N * sizeof(double));
    Y = (double*)aligned_alloc(32, N * sizeof(double));

    if (!X || !Y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (double)(j % 1234);
        Y[j] = (double)(j % 5678);
    }
}