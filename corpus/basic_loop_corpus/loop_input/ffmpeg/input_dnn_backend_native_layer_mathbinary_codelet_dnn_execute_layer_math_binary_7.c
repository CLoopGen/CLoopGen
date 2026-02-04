#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dims_count;
float *src;
float *dst;
float *src1;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (256MB total for 3 arrays)
    dims_count = data_size / sizeof(float);

    src = (float*)aligned_alloc(32, data_size);
    dst = (float*)aligned_alloc(32, data_size);
    src1 = (float*)aligned_alloc(32, data_size);

    for (int i = 0; i < dims_count; ++i) {
        src[i] = 1.0f + (i % 100) * 0.01f;
        src1[i] = 2.0f + (i % 150) * 0.02f;
    }
}