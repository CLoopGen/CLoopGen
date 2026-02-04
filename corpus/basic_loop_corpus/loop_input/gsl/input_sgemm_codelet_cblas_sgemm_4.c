#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int K = 128;
float alpha = 1.234f;
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
    const size_t c_size = (size_t)ldc * n1;
    const size_t f_size = (size_t)ldf * K;
    const size_t g_size = (size_t)ldg * K;

    C = (float*)aligned_alloc(32, c_size * sizeof(float));
    F = (float*)aligned_alloc(32, f_size * sizeof(float));
    G = (float*)aligned_alloc(32, g_size * sizeof(float));

    for (size_t idx = 0; idx < c_size; idx++) {
        C[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < f_size; idx++) {
        F[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < g_size; idx++) {
        G[idx] = (float)(rand() % 100) / 100.0f;
    }

    alpha = 1.234f;
    K = 128;
    n1 = 128;
    n2 = 256;
    ldc = 256;
    ldf = 128;
    ldg = 256;
}