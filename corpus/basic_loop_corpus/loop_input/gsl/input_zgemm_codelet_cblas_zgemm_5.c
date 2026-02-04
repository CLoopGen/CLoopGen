#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 128;
void *C;
int ldc = 256;
int i, j, k;
int n1 = 256;
int n2 = 256;
int ldf = 128;
int ldg = 128;
int conjF = 1;
int conjG = 1;
double *F;
double *G;
double alpha_real = 1.0;
double alpha_imag = 0.5;

void init_vars() {
    F = aligned_alloc(32, sizeof(double) * 2 * ldf * K);
    G = aligned_alloc(32, sizeof(double) * 2 * ldg * n2);
    C = aligned_alloc(32, sizeof(double) * 2 * ldc * n1);

    for (int idx = 0; idx < 2 * ldf * K; idx++) {
        F[idx] = (double)(idx % 127) / 127.0;
    }
    for (int idx = 0; idx < 2 * ldg * n2; idx++) {
        G[idx] = (double)((idx + 19) % 131) / 131.0;
    }
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        ((double *)C)[idx] = (double)((idx + 43) % 137) / 137.0;
    }
}