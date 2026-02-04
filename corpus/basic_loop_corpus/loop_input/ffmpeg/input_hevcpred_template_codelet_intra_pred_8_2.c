#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 1024;
ptrdiff_t stride = 1024;
uint8_t *src;
uint8_t *left;
int bottom_left_size = 1024 * 256; // ~256MB of data for ~0.01 sec runtime

void init_vars() {
    src = (uint8_t *)aligned_alloc(64, (size + bottom_left_size) * stride * sizeof(uint8_t));
    left = (uint8_t *)aligned_alloc(64, (size + bottom_left_size) * sizeof(uint8_t));

    if (!src || !left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < (size + bottom_left_size) * stride; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }
    for (int j = 0; j < size + bottom_left_size; j++) {
        left[j] = 0;
    }
}