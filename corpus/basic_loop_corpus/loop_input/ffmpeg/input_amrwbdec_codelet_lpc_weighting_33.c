#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

float *out;
float *lpc;
float gamma;
int size;
int i;
float fac;

void init_vars() {
    size = 16777216; // 64 MB of float data (16M elements * 4 bytes * 2 arrays ≈ 128 MB total)

    out = (float*)aligned_alloc(32, size * sizeof(float));
    lpc = (float*)aligned_alloc(32, size * sizeof(float));

    gamma = 0.999f;
    fac = 1.0f;

    for (int idx = 0; idx < size; idx++) {
        lpc[idx] = 1.0f + (idx % 100) * 0.01f;
        out[idx] = 0.0f;
    }
}