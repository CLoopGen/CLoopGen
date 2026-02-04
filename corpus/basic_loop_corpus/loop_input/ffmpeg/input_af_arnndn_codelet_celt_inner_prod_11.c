#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *y;
int N;
float xy;

void init_vars() {
    N = 67108864; // Approximately 256MB of input data (67M * 4B * 2 arrays)
    x = (float*)aligned_alloc(32, N * sizeof(float));
    y = (float*)aligned_alloc(32, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        x[i] = 1.0f + (i % 100) * 0.01f;
        y[i] = 0.5f + (i % 75) * 0.02f;
    }
    xy = 0.0f;
}