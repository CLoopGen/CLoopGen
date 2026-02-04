#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int K = 64;
int ldc = 128;
int i = 0;
int j = 0;
int k = 0;
int n1 = 64;
int n2 = 64;
int ldf = 64;
int ldg = 64;
int conjF = 1;
int conjG = 1;
float alpha_real = 1.5f;
float alpha_imag = 0.5f;

float *F;
float *G;
void *C;

void init_vars() {
    F = (float*)aligned_alloc(32, 2 * ldf * K * sizeof(float));
    G = (float*)aligned_alloc(32, 2 * ldg * K * n2 * sizeof(float));
    C = aligned_alloc(32, 2 * ldc * n1 * n2 * sizeof(float));

    for (int idx = 0; idx < 2 * ldf * K; idx++) {
        F[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < 2 * ldg * K * n2; idx++) {
        G[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < 2 * ldc * n1 * n2; idx++) {
        ((float*)C)[idx] = 0.0f;
    }
}