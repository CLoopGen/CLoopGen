#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int N = 2048;
int K = 128;
double *A;
int lda = 2048;
double *X;
int incX = 1;
int nonunit = 1;
int i;
int j;
int ix;

void init_vars() {
    const size_t A_size = (size_t)lda * N;
    const size_t X_size = (size_t)(incX > 0 ? N : 1) + (N - 1) * (incX < 0 ? -incX : 0);

    A = (double*)aligned_alloc(32, A_size * sizeof(double));
    X = (double*)aligned_alloc(32, X_size * sizeof(double));

    if (!A || !X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < A_size; ++idx) {
        A[idx] = (double)(rand() % 1000) / 100.0;
    }

    for (size_t idx = 0; idx < X_size; ++idx) {
        X[idx] = (double)(rand() % 1000) / 100.0;
    }

    i = 0;
    j = 0;
    ix = 0;
}