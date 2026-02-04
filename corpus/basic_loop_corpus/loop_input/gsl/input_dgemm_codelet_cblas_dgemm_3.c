#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 256;
double alpha = 1.5;

int ldc = 512;
int i, j, k;
int n1 = 512;
int n2 = 512;
int ldf = 256;
int ldg = 256;

double *C;
double *F;
double *G;

void init_vars() {
    C = (double*)aligned_alloc(32, sizeof(double) * ldc * n2);
    F = (double*)aligned_alloc(32, sizeof(double) * ldf * n1);
    G = (double*)aligned_alloc(32, sizeof(double) * ldg * n2);

    for (int idx = 0; idx < ldc * n2; idx++) {
        C[idx] = 1.0;
    }
    for (int idx = 0; idx < ldf * n1; idx++) {
        F[idx] = 1.0 + (idx % 2) * 0.5;
    }
    for (int idx = 0; idx < ldg * n2; idx++) {
        G[idx] = 1.0 - (idx % 2) * 0.5;
    }
}