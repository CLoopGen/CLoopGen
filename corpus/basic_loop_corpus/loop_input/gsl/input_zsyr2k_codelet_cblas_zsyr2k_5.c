#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 512;
int lda = 512;
int ldb = 512;

void *A;
void *B;
void *C;

int i, j, k;

double alpha_real = 1.5;
double alpha_imag = 0.8;

void init_vars() {
    A = aligned_alloc(32, 2 * N * K * sizeof(double));
    B = aligned_alloc(32, 2 * N * K * sizeof(double));
    C = aligned_alloc(32, 2 * N * N * sizeof(double));

    double *ptrA = (double *)A;
    double *ptrB = (double *)B;
    double *ptrC = (double *)C;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        ptrA[idx] = (double)(idx % 127) / 127.0;
        ptrB[idx] = (double)((idx + 31) % 127) / 127.0;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        ptrC[idx] = 0.0;
    }
}