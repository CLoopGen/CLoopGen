#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 2048;
float *Ap;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    Ap = (float*)aligned_alloc(32, sizeof(float) * ((N * (N + 1)) / 2));
    X = (float*)aligned_alloc(32, sizeof(float) * (N * abs(incX)));

    for (int idx = 0; idx < (N * (N + 1)) / 2; idx++) {
        Ap[idx] = 1.0f + 0.01f * (idx % 100);
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx * abs(incX)] = 2.0f + 0.1f * (idx % 50);
    }
}