#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int K = 128;
int ldc = 256;
int i, j, k;
int n1 = 128;
int n2 = 128;
int ldf = 128;
int ldg = 128;
int conjF = 1;
int conjG = 1;
float alpha_real = 1.5f;
float alpha_imag = 0.8f;

float *F;
float *G;
void *C;

void init_vars() {
    const size_t size_F = 2 * ldf * K;
    const size_t size_G = 2 * ldg * K;
    const size_t size_C = 2 * ldc * n1 * n2;

    F = (float*)aligned_alloc(32, size_F * sizeof(float));
    G = (float*)aligned_alloc(32, size_G * sizeof(float));
    C = aligned_alloc(32, size_C * sizeof(float));

    for (size_t idx = 0; idx < size_F; idx++) {
        F[idx] = (float)(drand48() * 2.0 - 1.0);
    }

    for (size_t idx = 0; idx < size_G; idx++) {
        G[idx] = (float)(drand48() * 2.0 - 1.0);
    }

    for (size_t idx = 0; idx < size_C; idx++) {
        ((float*)C)[idx] = 0.0f;
    }
}