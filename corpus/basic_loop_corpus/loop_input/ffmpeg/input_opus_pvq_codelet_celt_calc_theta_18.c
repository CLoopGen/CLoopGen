#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *X;
float *Y;
int N;
int i;
float e[2];

void init_vars() {
    N = 32 * 1024 * 1024 / sizeof(float);  // ~128 MB of float data (64M floats total, 32M per array)
    
    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100) + 1.0f;
        Y[j] = (float)((j + 50) % 100) + 0.5f;
    }

    e[0] = 0.0f;
    e[1] = 0.0f;
    i = 0;
}