#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 64;
double alpha = 1.5;

double *A;
int lda;

double *X;
int incX;

double *Y;
int incY;

int i;
int j;
int ix;
int iy;

void init_vars() {
    lda = N;
    incX = 1;
    incY = 1;

    A = (double*)calloc(N * N, sizeof(double));
    X = (double*)malloc(N * sizeof(double));
    Y = (double*)malloc(N * sizeof(double));

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = (double)(idx % 128) / 64.0;
        Y[idx] = (double)(idx % 256) / 32.0;
    }

    for (int row = 0; row < N; ++row) {
        int start = row + 1;
        int end = (N < row + K + 1) ? (row + K + 1) : N;
        for (int col_idx = start; col_idx < end; ++col_idx) {
            A[(col_idx - row) + row * lda] = (double)((row + col_idx) % 256) / 128.0;
        }
    }

    ix = 0;
    iy = 0;
}