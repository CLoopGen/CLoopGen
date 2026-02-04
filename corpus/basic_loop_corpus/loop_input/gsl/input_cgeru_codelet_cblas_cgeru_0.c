#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int M = 256;
int N = 256;
void *X;
int incX = 1;
void *Y;
int incY = 1;
void *A;
int lda = 256;
int i;
int j;
float alpha_real = 0.866025f; // cos(π/6)
float alpha_imag = 0.5f;      // sin(π/6)
int ix = 0;

void init_vars() {
    X = aligned_alloc(32, 2 * M * sizeof(float));
    Y = aligned_alloc(32, 2 * N * sizeof(float));
    A = aligned_alloc(32, 2 * M * N * sizeof(float));

    float *X_float = (float *)X;
    float *Y_float = (float *)Y;
    float *A_float = (float *)A;

    for (int idx = 0; idx < 2 * M; idx++) {
        X_float[idx] = (float)(idx % 7) * 0.1f;
    }

    for (int idx = 0; idx < 2 * N; idx++) {
        Y_float[idx] = (float)((idx + 3) % 5) * 0.2f;
    }

    for (int idx = 0; idx < 2 * M * N; idx++) {
        A_float[idx] = 0.0f;
    }
}