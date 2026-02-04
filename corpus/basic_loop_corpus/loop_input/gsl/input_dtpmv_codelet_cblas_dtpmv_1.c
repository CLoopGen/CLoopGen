#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
double *Ap;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    Ap = (double*)aligned_alloc(32, sizeof(double) * ((N * (N + 1)) / 2));
    X = (double*)aligned_alloc(32, sizeof(double) * N);
    if (!Ap || !X) {
        exit(1);
    }

    for (int k = 0; k < (N * (N + 1)) / 2; k++) {
        Ap[k] = 1.0 + (k % 7) * 0.1;
    }
    for (int k = 0; k < N; k++) {
        X[k] = 2.0 + (k % 5) * 0.2;
    }

    ix = (incX > 0 ? N - 1 : 0);
}