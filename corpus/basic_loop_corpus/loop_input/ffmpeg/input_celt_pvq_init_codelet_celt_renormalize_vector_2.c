#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
int N = 1 << 20;  // Approximately 4MB of data (1M floats)
int i;
float g = 2.5f;

void init_vars() {
    X = (float *)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100);
    }
}