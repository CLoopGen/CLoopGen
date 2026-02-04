#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 128;
double alpha = 1.5;
int ldc = 256;
int i, j, k;
int n1 = 128;
int n2 = 256;
int ldf = 128;
int ldg = 256;

double *C;
double *F;
double *G;

void init_vars() {
    C = (double*)calloc(ldc * n2, sizeof(double));
    F = (double*)malloc(ldf * K * sizeof(double));
    G = (double*)malloc(ldg * K * sizeof(double));

    for (int idx = 0; idx < ldf * K; idx++) {
        F[idx] = (double)(idx % 17) * 0.1;
    }

    for (int idx = 0; idx < ldg * K; idx++) {
        G[idx] = (double)(idx % 19) * 0.1;
    }
}