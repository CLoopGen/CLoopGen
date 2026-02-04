#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dims_count;
float *src;
float *dst;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (2^23 elements)
    dims_count = data_size / sizeof(float);

    src = (float*)aligned_alloc(32, data_size);
    dst = (float*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(rand() - RAND_MAX / 2);
    }
}