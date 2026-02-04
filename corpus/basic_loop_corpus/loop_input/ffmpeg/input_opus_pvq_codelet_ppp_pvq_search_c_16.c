#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
int N = 1 << 20; // Approximately 4MB of data (1M floats), suitable for ~0.01 sec runtime
int i;
float res;

void init_vars() {
    X = (float *)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        X[j] = (float)(rand() - RAND_MAX / 2);
    }
    i = 0;
    res = 0.0f;
}