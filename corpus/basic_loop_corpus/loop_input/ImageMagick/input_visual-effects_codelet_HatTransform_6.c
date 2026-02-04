#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t stride = 1;
size_t extent = 67108864; // ~64M elements to target ~0.01 sec runtime
size_t scale = 16;
float *kernel;
float *restrict p;
ssize_t i = 0;

void init_vars() {
    const size_t total_size = extent + scale * 2;
    float *data_pool = (float*)aligned_alloc(32, sizeof(float) * total_size);
    if (!data_pool) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    kernel = (float*)aligned_alloc(32, sizeof(float) * extent);
    if (!kernel) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data pool with dummy values
    for (size_t idx = 0; idx < total_size; idx++) {
        data_pool[idx] = (float)(idx % 1000) / 1000.0F;
    }

    // Set p to point at the center offset by 'scale' to allow safe access
    p = data_pool + scale * stride;
}