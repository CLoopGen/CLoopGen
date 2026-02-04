#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

int N = 512;
int K = 512;
double alpha = 1.5;

int lda = 512;
int ldc = 512;

double *A;
double *C;

int i;
int j;
int k;

void init_vars() {
    A = (double*)aligned_alloc(32, sizeof(double) * (size_t)(N * lda));
    C = (double*)aligned_alloc(32, sizeof(double) * (size_t)(N * ldc));

    if (!A || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < N * lda; idx++) {
        A[idx] = (double)(idx % 17) + 1.0;
    }

    for (int idx = 0; idx < N * ldc; idx++) {
        C[idx] = (double)(idx % 19) + 0.5;
    }
}