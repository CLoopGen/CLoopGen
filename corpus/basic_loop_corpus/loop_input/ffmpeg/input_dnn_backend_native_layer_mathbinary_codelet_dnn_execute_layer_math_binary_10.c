#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int dims_count;
float *src;
float *dst;
float *src1;

void init_vars() {
    const size_t target_size_bytes = 64 * 1024 * 1024; 
    const size_t element_size = sizeof(float);
    dims_count = target_size_bytes / element_size;

    src = (float*)aligned_alloc(32, dims_count * sizeof(float));
    dst = (float*)aligned_alloc(32, dims_count * sizeof(float));
    src1 = (float*)aligned_alloc(32, dims_count * sizeof(float));

    if (!src || !dst || !src1) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(rand() % 100 + 1);
        src1[i] = (float)(rand() % 100 + 1); 
        dst[i] = 0.0f;
    }
}