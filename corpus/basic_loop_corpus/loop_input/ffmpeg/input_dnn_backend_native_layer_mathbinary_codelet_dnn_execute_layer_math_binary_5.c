#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dims_count;
float *src;
float *dst;
float *src1;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~768 MB of total float data (3 arrays), ~256MB per array
    dims_count = data_size / sizeof(float);

    src = (float*)aligned_alloc(32, dims_count * sizeof(float));
    dst = (float*)aligned_alloc(32, dims_count * sizeof(float));
    src1 = (float*)aligned_alloc(32, dims_count * sizeof(float));

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(i % 1000) / 10.0f;
        src1[i] = (float)((i + 500) % 1000) / 15.0f;
        dst[i] = 0.0f;
    }
}