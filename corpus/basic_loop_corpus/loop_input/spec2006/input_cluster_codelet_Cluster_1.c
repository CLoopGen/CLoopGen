#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int N = 1 << 24; // Approximately 16.7 million elements, ~64 MB for float
int i;
float *diff;

void init_vars() {
    diff = (float *)aligned_alloc(32, N * sizeof(float));
    if (!diff) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        diff[j] = 1.0f; // Initialize to non-zero to make effect of loop visible
    }
}