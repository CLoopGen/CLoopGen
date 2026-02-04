#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float alpha = 1.5f;
float *X;
int incX = 1;
float *Ap;
int i;
int j;
int ix = 0;

void init_vars() {
    X = (float *)aligned_alloc(32, N * incX * sizeof(float));
    Ap = (float *)aligned_alloc(32, (N * (N + 1)) / 2 * sizeof(float));

    for (int k = 0; k < N * incX; k++) {
        X[k] = 1.0f + k * 0.01f;
    }

    int ap_size = (N * (N + 1)) / 2;
    for (int k = 0; k < ap_size; k++) {
        Ap[k] = 0.0f;
    }
}