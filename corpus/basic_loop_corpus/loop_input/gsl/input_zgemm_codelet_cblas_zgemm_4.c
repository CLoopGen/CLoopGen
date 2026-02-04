#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int K = 128;
int ldc = 256;
int i, j, k;
int n1 = 256;
int n2 = 256;
int ldf = 256;
int ldg = 256;
int conjF = 1;
int conjG = 1;
double alpha_real = 1.5;
double alpha_imag = 0.8;

void *C;
double *F;
double *G;

void init_vars() {
    const size_t size_C = 2 * ldc * n1 * sizeof(double);
    const size_t size_F = 2 * ldf * K * sizeof(double);
    const size_t size_G = 2 * ldg * K * sizeof(double);

    C = aligned_alloc(32, size_C);
    F = (double*)aligned_alloc(32, size_F);
    G = (double*)aligned_alloc(32, size_G);

    memset(C, 0, size_C);
    for (int idx = 0; idx < 2 * ldf * K; idx++) {
        F[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < 2 * ldg * K; idx++) {
        G[idx] = (double)((idx + 13) % 97) / 97.0;
    }
}