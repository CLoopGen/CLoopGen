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
    const size_t input_size = 64 * 1024 * 1024; // ~64MB of input data per array
    w2 = input_size / sizeof(int32_t); // number of int32_t elements

    dst = (int32_t*)aligned_alloc(32, 2 * w2 * sizeof(int32_t));
    src0 = (int32_t*)aligned_alloc(32, w2 * sizeof(int32_t));
    src1 = (int32_t*)aligned_alloc(32, w2 * sizeof(int32_t));

    add = 12345;
    shift = 2;
    i = 0;

    for (int j = 0; j < w2; j++) {
        src0[j] = rand();
        src1[j] = rand();
    }

    for (int j = 0; j < 2 * w2; j++) {
        dst[j] = 0;
    }
}