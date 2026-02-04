#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *X;
int N = 262144; // Approximately 1MB of float data (262144 * 4 bytes)
int i;
float g;

void init_vars() {
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx] = (float)(idx % 100) + 1.0f;
    }

    i = 0;
    g = 0.0f;
}