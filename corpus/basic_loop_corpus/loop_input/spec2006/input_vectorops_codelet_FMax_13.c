#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

float *vec;
int n = 1 << 20; // Approximately 4MB of data (1M floats)
int i;
float best;

void init_vars() {
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        exit(1);
    }
    for (int j = 0; j < n; j++) {
        vec[j] = (float)(rand() % 10000) / 100.0f;
    }
    best = vec[0];
    i = 0;
}