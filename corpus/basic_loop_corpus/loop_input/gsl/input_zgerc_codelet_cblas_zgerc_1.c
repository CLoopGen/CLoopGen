#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int M = 2048;
int N = 2048;
void *X;
int incX = 1;
void *Y;
int incY = 1;
void *A;
int lda = 2048;
int i;
int j;
double alpha_real = 1.5;
double alpha_imag = 0.8;
int jy = 0;

void init_vars() {
    const size_t size_X = (size_t)M * 2 * sizeof(double);
    const size_t size_Y = (size_t)N * 2 * sizeof(double);
    const size_t size_A = (size_t)M * N * 2 * sizeof(double);

    X = aligned_alloc(32, size_X);
    Y = aligned_alloc(32, size_Y);
    A = aligned_alloc(32, size_A);

    if (!X || !Y || !A) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }

    memset(X, 0, size_X);
    memset(Y, 0, size_Y);
    memset(A, 0, size_A);

    double *X_d = (double *)X;
    double *Y_d = (double *)Y;
    double *A_d = (double *)A;

    for (size_t idx = 0; idx < M * 2; idx++) {
        X_d[idx] = (double)(idx % 127) / 127.0;
    }

    for (size_t idx = 0; idx < N * 2; idx++) {
        Y_d[idx] = (double)((idx + 37) % 97) / 97.0;
    }

    for (size_t idx = 0; idx < (size_t)M * N * 2; idx++) {
        A_d[idx] = (double)((idx + 19) % 43) / 43.0;
    }
}