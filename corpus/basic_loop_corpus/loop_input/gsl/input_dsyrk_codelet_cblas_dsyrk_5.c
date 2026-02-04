#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 1024;
int K = 128;
double alpha = 1.5;

double *A;
int lda = 1024;
double *C;
int ldc = 1024;

int i, j, k;

void init_vars() {
    const size_t size_a = (size_t)lda * K * sizeof(double);
    const size_t size_c = (size_t)ldc * N * sizeof(double);

    A = (double*)aligned_alloc(32, size_a);
    C = (double*)aligned_alloc(32, size_c);

    if (!A || !C) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < K * lda; idx++) {
        A[idx] = ((double)rand()) / RAND_MAX;
    }

    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = ((double)rand()) / RAND_MAX;
    }
}