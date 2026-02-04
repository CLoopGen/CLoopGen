#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int K = 128;
float alpha = 1.5f;

int ldc = 256;
int i, j, k;
int n1 = 256;
int n2 = 256;
int ldf = 128;
int ldg = 128;

float *C;
float *F;
float *G;

void init_vars() {
    const size_t size_c = (size_t)ldc * n2;
    const size_t size_f = (size_t)ldf * n1;
    const size_t size_g = (size_t)ldg * K;

    C = (float*)aligned_alloc(32, size_c * sizeof(float));
    F = (float*)aligned_alloc(32, size_f * sizeof(float));
    G = (float*)aligned_alloc(32, size_g * sizeof(float));

    for (size_t idx = 0; idx < size_c; idx++) {
        C[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (size_t idx = 0; idx < size_f; idx++) {
        F[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (size_t idx = 0; idx < size_g; idx++) {
        G[idx] = (float)(rand() % 100) / 10.0f;
    }
}