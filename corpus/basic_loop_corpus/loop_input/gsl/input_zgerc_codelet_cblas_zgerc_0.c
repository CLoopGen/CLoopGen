#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 512;
int N = 512;
void *X;
int incX = 1;
void *Y;
int incY = 1;
void *A;
int lda = 512;
int i;
int j;
double alpha_real = 1.5;
double alpha_imag = 0.8;
int ix = 0;

void init_vars() {
    const size_t x_size = (size_t)M * sizeof(double) * 2;
    const size_t y_size = (size_t)N * sizeof(double) * 2;
    const size_t a_size = (size_t)lda * N * sizeof(double) * 2;

    X = aligned_alloc(32, x_size);
    Y = aligned_alloc(32, y_size);
    A = aligned_alloc(32, a_size);

    if (!X || !Y || !A) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }

    double *X_ptr = (double *)X;
    double *Y_ptr = (double *)Y;
    double *A_ptr = (double *)A;

    for (size_t k = 0; k < M * 2; k++) {
        X_ptr[k] = (double)(k % 127) / 127.0;
    }

    for (size_t k = 0; k < N * 2; k++) {
        Y_ptr[k] = (double)((k + 31) % 97) / 97.0;
    }

    for (size_t k = 0; k < lda * N * 2; k++) {
        A_ptr[k] = (double)((k + 43) % 101) / 101.0;
    }
}