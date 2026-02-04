#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int M = 1024;
int N = 1024;
void *X;
int incX = 1;
void *Y;
int incY = 1;
void *A;
int lda = 1024;
int i;
int j;
double alpha_real = 1.5;
double alpha_imag = 0.8;
int jy = 0;

void init_vars() {
    X = aligned_alloc(32, 2 * M * sizeof(double));
    Y = aligned_alloc(32, 2 * N * sizeof(double));
    A = aligned_alloc(32, 2 * M * N * sizeof(double));

    double *X_d = (double *)X;
    double *Y_d = (double *)Y;
    double *A_d = (double *)A;

    for (int idx = 0; idx < 2 * M; idx++) {
        X_d[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * N; idx++) {
        Y_d[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * M * N; idx++) {
        A_d[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}