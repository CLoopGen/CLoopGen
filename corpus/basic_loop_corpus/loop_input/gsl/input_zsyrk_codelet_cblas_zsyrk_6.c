#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
int lda = 256;
int ldc = 512;
int i, j, k;
double alpha_real = 1.5;
double alpha_imag = 0.8;

void *A;
void *C;

void init_vars() {
    A = aligned_alloc(32, 2 * N * lda * sizeof(double));
    C = aligned_alloc(32, 2 * N * ldc * sizeof(double));

    if (!A || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    double *Ap = (double *)A;
    double *Cp = (double *)C;

    for (int idx = 0; idx < 2 * N * lda; idx++) {
        Ap[idx] = (double)(idx % 123) * 0.01;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        Cp[idx] = (double)(idx % 456) * 0.02;
    }
}