#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *X;
int N = 1 << 20; // Approximately 4MB of data (1M floats), adjust for ~0.01 sec runtime
int i;
float g;

void init_vars() {
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx] = (float)(idx % 1000) / 100.0f;
    }

    i = 0;
    g = 0.0f;
}