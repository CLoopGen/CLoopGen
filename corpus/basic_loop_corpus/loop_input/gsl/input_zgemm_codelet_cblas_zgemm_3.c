#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int K = 128;
void *C;
int ldc = 256;
int i, j, k;
int n1 = 128;
int n2 = 128;
int ldf = 128;
int ldg = 128;
int conjF = 1;
int conjG = 1;
double *F;
double *G;
double alpha_real = 1.0;
double alpha_imag = 0.5;

void init_vars() {
    F = (double*)aligned_alloc(32, 2 * ldf * K * sizeof(double));
    G = (double*)aligned_alloc(32, 2 * ldg * K * sizeof(double));
    C = aligned_alloc(32, 2 * ldc * n1 * sizeof(double));

    for (int idx = 0; idx < 2 * ldf * K; idx++) {
        F[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < 2 * ldg * K; idx++) {
        G[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        ((double*)C)[idx] = 0.0;
    }
}