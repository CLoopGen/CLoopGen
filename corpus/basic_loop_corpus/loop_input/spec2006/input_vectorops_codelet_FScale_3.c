#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n;
float scale;
int x;

void init_vars() {
    n = 1 << 24; // Approximately 16.7 million elements, ~64 MB of data (16.7M * 4 bytes)
    vec = (float *)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        vec[i] = (float)(i % 1000) + 0.5f;
    }

    scale = 1.5f;
    x = 0;
}