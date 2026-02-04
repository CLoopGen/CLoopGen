#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 512;
void *A;
int lda = 512;
void *C;
int ldc = 512;
int i;
int j;
int k;
double alpha_real = 1.0;
double alpha_imag = 0.5;

void init_vars() {
    A = aligned_alloc(32, 2 * N * K * sizeof(double));
    C = aligned_alloc(32, 2 * N * N * sizeof(double));

    if (!A || !C) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    double *A_ptr = (double *)A;
    double *C_ptr = (double *)C;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_ptr[idx] = (double)(idx % 127) / 10.0;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_ptr[idx] = (double)(idx % 251) / 20.0;
    }
}