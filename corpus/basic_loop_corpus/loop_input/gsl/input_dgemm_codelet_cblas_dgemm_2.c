#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 512;
double alpha = 1.5;
int ldc = 1024;
int i, j, k;
int n1 = 512;
int n2 = 512;
int ldf = 512;
int ldg = 512;

double *C;
double *F;
double *G;

void init_vars() {
    C = (double*)calloc(ldc * n2, sizeof(double));
    F = (double*)malloc(ldf * K * sizeof(double));
    G = (double*)malloc(ldg * n2 * sizeof(double));

    for (int idx = 0; idx < ldf * K; idx++) {
        F[idx] = (double)(idx % 128) / 128.0;
    }
    for (int idx = 0; idx < ldg * n2; idx++) {
        G[idx] = (double)(idx % 128) / 64.0;
    }
}