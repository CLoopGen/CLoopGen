#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;

float *Ap;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    Ap = (float*)aligned_alloc(32, ((N * (N + 1)) / 2) * sizeof(float));
    X = (float*)aligned_alloc(32, N * sizeof(float));

    for (int idx = 0; idx < (N * (N + 1)) / 2; ++idx) {
        Ap[idx] = 1.0f + (idx % 100) * 0.01f;
    }

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 0.5f + idx * 0.001f;
    }

    i = 0;
    j = 0;
    ix = 0;
}