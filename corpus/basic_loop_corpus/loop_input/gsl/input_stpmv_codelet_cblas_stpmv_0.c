#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
float *Ap;
float *X;
int incX = 1;
int i = 0;
int j = 0;
int nonunit = 1;
int ix = 0;

void init_vars() {
    Ap = (float*)aligned_alloc(32, sizeof(float) * (N * (N + 1)) / 2);
    X = (float*)aligned_alloc(32, sizeof(float) * (N * 2));
    if (!Ap || !X) {
        exit(1);
    }

    for (int idx = 0; idx < (N * (N + 1)) / 2; idx++) {
        Ap[idx] = 1.0f + (idx % 7) * 0.1f;
    }

    for (int idx = 0; idx < N * 2; idx++) {
        X[idx] = 2.0f + (idx % 5) * 0.05f;
    }

    ix = 0;
    incX = 1;
    nonunit = 1;
}