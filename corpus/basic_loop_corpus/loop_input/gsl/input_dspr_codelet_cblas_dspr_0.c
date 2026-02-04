#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
double alpha;
double *X;
int incX;
double *Ap;
int i;
int j;
int ix;

void init_vars() {
    N = 2048;
    alpha = 1.5;
    incX = 1;
    ix = 0;

    X = (double*)aligned_alloc(32, N * sizeof(double));
    if (!X) exit(1);
    for (int k = 0; k < N; ++k) {
        X[k] = (double)(k + 1);
    }

    int ap_size = (N * (N + 1)) / 2;
    Ap = (double*)aligned_alloc(32, ap_size * sizeof(double));
    if (!Ap) exit(1);
    for (int k = 0; k < ap_size; ++k) {
        Ap[k] = 0.0;
    }
}