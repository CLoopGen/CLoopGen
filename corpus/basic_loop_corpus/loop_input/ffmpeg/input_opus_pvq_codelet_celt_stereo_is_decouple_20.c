#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *Y;
float e_l;
float e_r;
int N;
int i;

void init_vars() {
    N = 1 << 20; // Approximately 4 million elements, ~16MB per array

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    e_l = 0.5f;
    e_r = 0.8f;
    i = 0;

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100) * 0.01f;
        Y[j] = 2.0f + (j % 75)  * 0.02f;
    }
}