#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N;
float *Ap;
float *X;
int incX;
int i;
int j;
int nonunit;
int ix;

void init_vars() {
    N = 2048;

    Ap = (float *)aligned_alloc(32, sizeof(float) * (N * (N + 1)) / 2);
    X = (float *)aligned_alloc(32, sizeof(float) * N);

    incX = 1;
    nonunit = 1;
    ix = 0;

    for (int idx = 0; idx < (N * (N + 1)) / 2; ++idx) {
        Ap[idx] = 1.0f + 0.01f * (rand() / (float)RAND_MAX);
    }

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = (rand() / (float)RAND_MAX);
    }
}