#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *X;
float *lowband_out;
int i;
uint32_t N0;
float n;

void init_vars() {
    N0 = 67108864; // 64M elements, ~256MB total data (two float arrays)
    n = 1.5f;

    X = (float *)aligned_alloc(32, N0 * sizeof(float));
    lowband_out = (float *)aligned_alloc(32, N0 * sizeof(float));

    if (!X || !lowband_out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint32_t idx = 0; idx < N0; idx++) {
        X[idx] = (float)(idx % 1000) / 100.0f;
        lowband_out[idx] = 0.0f;
    }
}