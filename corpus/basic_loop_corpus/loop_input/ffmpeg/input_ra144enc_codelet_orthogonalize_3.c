#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *v;
float *u;
int i;
float num;
float den;

void init_vars() {
    size_t array_size = 1 << 20; // ~4MB total (2 arrays of float, each ~4MB)
    v = (float*)aligned_alloc(32, array_size * sizeof(float));
    u = (float*)aligned_alloc(32, array_size * sizeof(float));

    for (size_t idx = 0; idx < array_size; idx++) {
        v[idx] = (float)(idx % 128) * 0.5f;
        u[idx] = (float)(idx % 64) * 0.25f;
    }

    i = 0;
    num = 0.0f;
    den = 0.0f;
}