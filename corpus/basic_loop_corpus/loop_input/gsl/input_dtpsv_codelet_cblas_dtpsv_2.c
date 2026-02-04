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

    Ap = (double*)aligned_alloc(64, sizeof(double) * (N * (N + 1)) / 2);
    X = (double*)aligned_alloc(64, sizeof(double) * (N));

    incX = 1;
    nonunit = 1;
    i = 0;
    j = 0;
    ix = 0;

    for (int k = 0; k < (N * (N + 1)) / 2; k++) {
        Ap[k] = 1.0 + 0.01 * (k % 128);
    }

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k + 1);
    }
}