#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float *Ap;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    Ap = (float *)aligned_alloc(32, sizeof(float) * ((N * (N + 1)) / 2));
    X = (float *)aligned_alloc(32, sizeof(float) * (abs(incX) * (N - 1) + 1));

    for (int idx = 0; idx < (N * (N + 1)) / 2; ++idx) {
        Ap[idx] = 1.0f + 0.01f * (idx % 128);
    }

    for (int idx = 0; idx < abs(incX) * (N - 1) + 1; ++idx) {
        X[idx] = 2.0f + 0.02f * (idx % 64);
    }

    i = N - 1;
    ix = (N - 1) * incX;
}