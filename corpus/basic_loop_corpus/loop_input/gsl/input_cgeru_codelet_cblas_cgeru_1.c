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
    X = aligned_alloc(32, sizeof(float) * 2 * M);
    Y = aligned_alloc(32, sizeof(float) * 2 * N);
    A = aligned_alloc(32, sizeof(float) * 2 * M * N);

    float *X_float = (float *)X;
    float *Y_float = (float *)Y;
    float *A_float = (float *)A;

    for (int idx = 0; idx < 2 * M; idx++) {
        X_float[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < 2 * N; idx++) {
        Y_float[idx] = (float)(idx % 100) / 100.0f;
    }

    for (int idx = 0; idx < 2 * M * N; idx++) {
        A_float[idx] = 0.0f;
    }
}