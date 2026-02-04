#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 1024;
ptrdiff_t stride = 1024;
uint16_t *src;
uint16_t *left;
int bottom_left_size = 1024 * 50; // Adjusted for ~0.01 sec runtime

void init_vars() {
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (size + bottom_left_size) * stride + 32);
    left = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (size + bottom_left_size + 1));

    if (!src || !left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < (size + bottom_left_size) * stride + 32; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (int idx = 0; idx < size + bottom_left_size + 1; idx++) {
        left[idx] = 0;
    }
}