#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int32_t *src0;
int32_t *src1;
int w2;
int add;
int shift;
int i;

void init_vars() {
    const size_t input_size_bytes = 64 * 1024 * 1024; // ~64 MB for balanced workload
    const size_t num_elements = input_size_bytes / sizeof(int32_t);
    w2 = num_elements;

    dst = (int32_t*)aligned_alloc(32, 2 * w2 * sizeof(int32_t));
    src0 = (int32_t*)aligned_alloc(32, w2 * sizeof(int32_t));
    src1 = (int32_t*)aligned_alloc(32, w2 * sizeof(int32_t));

    add = 12345;
    shift = 2;
    i = 0;

    for (size_t idx = 0; idx < w2; idx++) {
        src0[idx] = (int32_t)(idx % 1000000);
        src1[idx] = (int32_t)((idx * 3) % 1000000);
    }

    for (size_t idx = 0; idx < 2 * w2; idx++) {
        dst[idx] = 0;
    }
}