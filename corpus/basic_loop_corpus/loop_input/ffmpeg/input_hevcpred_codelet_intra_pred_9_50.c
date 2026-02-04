#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 1024;
ptrdiff_t stride = 1024;
uint16_t *src;
uint16_t *left;
int bottom_left_size = 1024 * 100; // ~200KB of output data, ensures loop takes ~0.01s

void init_vars() {
    size = 1024;
    stride = 1024;
    bottom_left_size = 1024 * 100;

    src = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (size + bottom_left_size) * stride);
    left = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (size + bottom_left_size));

    if (!src || !left) {
        exit(1);
    }

    for (int idx = 0; idx < (size + bottom_left_size) * stride; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (int idx = 0; idx < size + bottom_left_size; idx++) {
        left[idx] = 0;
    }
}