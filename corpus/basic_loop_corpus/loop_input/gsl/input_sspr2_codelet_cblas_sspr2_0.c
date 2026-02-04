#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 2048;
float alpha = 1.5f;
float *X;
int incX = 1;
float *Y;
int incY = 1;
float *Ap;
int i;
int j;
int ix = 0;
int iy = 0;

void init_vars() {
    const int seed = 12345;
    srand(seed);

    X = (float*)aligned_alloc(32, N * incX * sizeof(float));
    Y = (float*)aligned_alloc(32, N * incY * sizeof(float));
    int ap_size = (N * (N + 1)) / 2;
    Ap = (float*)aligned_alloc(32, ap_size * sizeof(float));

    for (int k = 0; k < N; k++) {
        X[k * incX] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        Y[k * incY] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }
    for (int k = 0; k < ap_size; k++) {
        Ap[k] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }

    ix = 0;
    iy = 0;
}