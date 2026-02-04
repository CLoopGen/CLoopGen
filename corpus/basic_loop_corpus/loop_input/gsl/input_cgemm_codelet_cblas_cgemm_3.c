#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 128;
void *C;
int ldc = 256;
int i, j, k;
int n1 = 128;
int n2 = 128;
int ldf = 128;
int ldg = 128;
int conjF = 1;
int conjG = 1;
float *F;
float *G;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void init_vars() {
    F = (float *)aligned_alloc(32, 2 * ldf * K * sizeof(float));
    G = (float *)aligned_alloc(32, 2 * ldg * K * sizeof(float));
    C = aligned_alloc(32, 2 * ldc * n1 * sizeof(float));

    for (int idx = 0; idx < 2 * ldf * K; idx++) {
        F[idx] = (float)(idx % 127) / 127.0f;
    }
    for (int idx = 0; idx < 2 * ldg * K; idx++) {
        G[idx] = (float)((idx + 31) % 97) / 97.0f;
    }
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        ((float *)C)[idx] = (float)((idx + 47) % 53) / 53.0f;
    }
}