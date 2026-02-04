#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double beta;
double *Y;
int incY;
int i;
int iy;

void init_vars() {
    N = 10000000;  // 10 million elements for ~0.01 sec runtime
    beta = 1.5;
    incY = 1;
    iy = 0;

    Y = (double *)aligned_alloc(32, N * sizeof(double));
    if (!Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        Y[j] = (double)(j + 1);
    }
}