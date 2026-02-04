#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int16_t *src0;
int16_t *src1;
int w2;
int add;
int shift;
int i;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB of input data for sufficient workload
    const size_t num_elements = total_data_size / sizeof(int16_t) / 3; // src0, src1, and dst (dst needs 2x)

    w2 = (int)num_elements;
    add = 128;
    shift = 4;

    src0 = (int16_t*)aligned_alloc(32, w2 * sizeof(int16_t));
    src1 = (int16_t*)aligned_alloc(32, w2 * sizeof(int16_t));
    dst = (int16_t*)aligned_alloc(32, 2 * w2 * sizeof(int16_t));

    for (int j = 0; j < w2; j++) {
        src0[j] = (int16_t)(j & 0x7FF);
        src1[j] = (int16_t)((j + 64) & 0x7FF);
    }
}