#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
double alpha = 1.5;

double *Ap;
double *X;
int incX = 1;
double *Y;
int incY = 1;
int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    Ap = (double*)calloc((N * (N + 1)) / 2, sizeof(double));
    X = (double*)malloc(N * sizeof(double));
    Y = (double*)calloc(N, sizeof(double));

    for (int k = 0; k < N; k++) {
        X[k] = (double)(k % 7 + 1);
        Y[k] = (double)(k % 5 + 1);
    }

    int idx = 0;
    for (int row = 0; row < N; row++) {
        for (int col = row; col < N; col++) {
            Ap[idx++] = (double)((row * N + col) % 13 + 1);
        }
    }
}