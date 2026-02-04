#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 1024;
int N = 1024;

double X_data[2 * 1024] __attribute__((aligned(32)));
void *X = X_data;
int incX = 1;

double Y_data[2 * 1024] __attribute__((aligned(32)));
void *Y = Y_data;
int incY = 1;

double A_data[2 * 1024 * 1024] __attribute__((aligned(32)));
void *A = A_data;
int lda = 1024;

int i = 0;
int j = 0;
double alpha_real = 1.5;
double alpha_imag = 0.8;
int ix = 0;

void init_vars() {
    for (int idx = 0; idx < 2 * M; idx++) {
        X_data[idx] = (double)(idx % 128) / 64.0;
    }

    for (int idx = 0; idx < 2 * N; idx++) {
        Y_data[idx] = (double)((idx + 32) % 96) / 48.0;
    }

    const int A_size = 2 * M * N;
    for (int idx = 0; idx < A_size; idx++) {
        A_data[idx] = 0.0;
    }

    i = 0;
    j = 0;
    ix = 0;
}