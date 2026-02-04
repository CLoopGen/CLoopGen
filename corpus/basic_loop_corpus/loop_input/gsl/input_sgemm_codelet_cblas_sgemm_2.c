#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int K = 128;
float alpha = 1.23f;
int ldc = 256;
int i, j, k;
int n1 = 128;
int n2 = 256;
int ldf = 128;
int ldg = 256;

float *C;
float *F;
float *G;

void init_vars() {
    const size_t size_C = (size_t)ldc * n2;
    const size_t size_F = (size_t)ldf * K;
    const size_t size_G = (size_t)ldg * n2;

    C = (float*)calloc(size_C, sizeof(float));
    F = (float*)malloc(size_F * sizeof(float));
    G = (float*)malloc(size_G * sizeof(float));

    for (size_t idx = 0; idx < size_F; idx++) {
        F[idx] = (float)(idx % 128) * 0.1f;
    }

    for (size_t idx = 0; idx < size_G; idx++) {
        G[idx] = (float)(idx % 256) * 0.05f;
    }

    for (size_t idx = 0; idx < size_C; idx++) {
        C[idx] = (float)(rand()) / RAND_MAX * 0.01f;
    }
}