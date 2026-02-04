#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float *X;
int N = ARRAY_SIZE;
int i;
float g = 2.5f;

void init_vars() {
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100) * 0.01f;
    }

    g = 1.5f;
    i = 0;
}