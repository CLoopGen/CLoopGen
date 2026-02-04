#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 10000000;

float *X;
int incX = 1;
float *Y;
int incY = 1;
int n;
int i = 0;
int j = 0;
float h11 = 1.5f;
float h21 = 0.8f;
float h12 = -0.3f;
float h22 = 1.2f;

void init_vars() {
    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    for (int idx = 0; idx < N; idx++) {
        X[idx] = (float)(idx % 100) + 1.0f;
        Y[idx] = (float)((idx + 47) % 100) + 1.0f;
    }
}