#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *y01;
float *y02;
int N;
float xy01;
float xy02;

void init_vars() {
    N = 8388608; // Approximately 32 MB of data (8M * 4 bytes per float * 4 arrays), tuned for ~0.01s runtime

    x = (float*)aligned_alloc(32, N * sizeof(float));
    y01 = (float*)aligned_alloc(32, N * sizeof(float));
    y02 = (float*)aligned_alloc(32, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        x[i] = 1.0f + (i * 0.0001f);
        y01[i] = 2.0f + (i * 0.0002f);
        y02[i] = 3.0f + (i * 0.0003f);
    }

    xy01 = 0.0f;
    xy02 = 0.0f;
}