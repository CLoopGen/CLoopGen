#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
int N = 1 << 20; // Approximately 4MB of data (1M elements * 4 bytes)
int i;
float g;

void init_vars() {
    X = (float *)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx < N; idx++) {
        X[idx] = 1.0f;
    }
    i = 0;
    g = 0.0f;
}