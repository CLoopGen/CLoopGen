#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int K = 128;
int ldc = 256;
int i = 0;
int j = 0;
int k = 0;
int n1 = 128;
int n2 = 128;
int ldf = 128;
int ldg = 128;
int conjF = 1;
int conjG = 1;
double alpha_real = 1.5;
double alpha_imag = 0.8;

double *F;
double *G;
void *C;

void init_vars() {
    const size_t size_F = 2 * ldf * n1 * sizeof(double);
    const size_t size_G = 2 * ldg * n2 * sizeof(double);
    const size_t size_C = 2 * ldc * n2 * sizeof(double);

    F = aligned_alloc(32, size_F);
    G = aligned_alloc(32, size_G);
    C = aligned_alloc(32, size_C);

    for (size_t idx = 0; idx < 2 * ldf * n1; idx++) {
        F[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (size_t idx = 0; idx < 2 * ldg * n2; idx++) {
        G[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (size_t idx = 0; idx < 2 * ldc * n2; idx++) {
        ((double*)C)[idx] = 0.0;
    }
}