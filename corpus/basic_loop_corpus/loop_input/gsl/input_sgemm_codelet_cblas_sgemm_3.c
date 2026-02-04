#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int K = 128;
float alpha = 1.5f;

int ldc = 256;
int i, j, k;
int n1 = 256;
int n2 = 256;

int ldf = 128;
int ldg = 128;

float *F;
float *G;
float *C;

void init_vars() {
    F = (float*)aligned_alloc(32, sizeof(float) * ldf * n1);
    G = (float*)aligned_alloc(32, sizeof(float) * ldg * n2);
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * n1);

    for (int idx = 0; idx < ldf * n1; idx++) {
        F[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (int idx = 0; idx < ldg * n2; idx++) {
        G[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (int idx = 0; idx < ldc * n1; idx++) {
        C[idx] = (float)(rand() % 100) / 100.0f;
    }
}