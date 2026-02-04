#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int M = 1024;
int N = 1024;
void *X;
int incX = 1;
void *Y;
int incY = 1;
void *A;
int lda = 1024;
int i;
int j;
float alpha_real = 1.5f;
float alpha_imag = 0.8f;
int jy = 0;

void init_vars() {
    X = aligned_alloc(32, 2 * M * sizeof(float));
    Y = aligned_alloc(32, 2 * N * sizeof(float));
    A = aligned_alloc(32, 2 * M * N * sizeof(float));

    float *X_f = (float *)X;
    float *Y_f = (float *)Y;
    float *A_f = (float *)A;

    for (int idx = 0; idx < 2 * M; idx++) {
        X_f[idx] = (float)(idx % 128) / 64.0f;
    }

    for (int idx = 0; idx < 2 * N; idx++) {
        Y_f[idx] = (float)((idx + 32) % 128) / 64.0f;
    }

    for (int idx = 0; idx < 2 * M * N; idx++) {
        A_f[idx] = (float)(idx % 256) / 128.0f;
    }
}