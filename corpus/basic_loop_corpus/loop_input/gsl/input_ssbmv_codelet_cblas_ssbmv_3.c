#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
int K = 512;
float alpha = 1.23f;

float *A;
int lda;

float *X;
int incX;

float *Y;
int incY;

int i;
int j;
int ix;
int iy;

void init_vars() {
    lda = N;
    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;

    A = (float*)aligned_alloc(64, sizeof(float) * lda * N);
    X = (float*)aligned_alloc(64, sizeof(float) * N);
    Y = (float*)aligned_alloc(64, sizeof(float) * N);

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = 1.0f + idx * 0.01f;
        Y[idx] = 2.0f + idx * 0.02f;
    }

    for (int i_idx = 0; i_idx < N; ++i_idx) {
        for (int j_idx = 0; j_idx < N; ++j_idx) {
            int k_idx = K - i_idx + j_idx;
            if (k_idx >= 0 && k_idx <= 2*K && j_idx >= (i_idx > K ? i_idx - K : 0) && j_idx < i_idx) {
                A[k_idx + i_idx * lda] = 0.1f * (k_idx + 1);
            } else if (j_idx == i_idx) {
                A[K + i_idx * lda] = 1.0f;
            } else {
                A[k_idx + i_idx * lda] = 0.0f;
            }
        }
    }
}