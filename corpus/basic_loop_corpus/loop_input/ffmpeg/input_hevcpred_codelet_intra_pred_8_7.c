#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 1024;
ptrdiff_t stride = 1024;
uint8_t *src;
uint8_t *left;
int bottom_left_size = 1024 * 256; // ~256MB of data for sufficient runtime (~0.01 sec on modern CPU)

void init_vars() {
    src = aligned_alloc(64, (size + bottom_left_size) * stride * sizeof(uint8_t));
    left = aligned_alloc(64, (size + bottom_left_size) * sizeof(uint8_t));

    if (!src || !left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < (size + bottom_left_size) * stride; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
    for (int idx = 0; idx < size + bottom_left_size; idx++) {
        left[idx] = 0;
    }
}