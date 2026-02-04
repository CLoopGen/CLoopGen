#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *v;
float *u;
int i;
float num;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB for float arrays (64M elements each)
    v = (float*)aligned_alloc(32, data_size * sizeof(float));
    u = (float*)aligned_alloc(32, data_size * sizeof(float));

    if (!v || !u) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        v[idx] = (float)(idx % 1000) + 1.0f;
        u[idx] = (float)(idx % 500) + 0.5f;
    }

    num = 0.75f;
    i = 0;
}