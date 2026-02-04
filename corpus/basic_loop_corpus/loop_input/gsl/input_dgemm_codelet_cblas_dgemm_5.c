#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 128;
double alpha = 1.5;
int ldc = 256;
int i, j, k;
int n1 = 256;
int n2 = 256;
int ldf = 128;
int ldg = 128;

double *C;
double *F;
double *G;

void init_vars() {
    C = (double*)aligned_alloc(32, sizeof(double) * ldc * n2);
    F = (double*)aligned_alloc(32, sizeof(double) * ldf * K);
    G = (double*)aligned_alloc(32, sizeof(double) * ldg * n2);

    for (int idx = 0; idx < ldc * n2; idx++) {
        C[idx] = 1.0;
    }
    for (int idx = 0; idx < ldf * K; idx++) {
        F[idx] = 1.0 + (idx % 7) * 0.1;
    }
    for (int idx = 0; idx < ldg * n2; idx++) {
        G[idx] = 0.5 + (idx % 5) * 0.2;
    }
}