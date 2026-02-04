#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int i;
int num_pixels;

void init_vars() {
    num_pixels = 64 * 1024 * 1024 / sizeof(uint16_t); // ~128MB of data, adjust for performance
    size_t src_size = num_pixels * sizeof(uint16_t);
    size_t dst_size = num_pixels * sizeof(uint16_t);

    src = (uint8_t *)aligned_alloc(16, src_size);
    dst = (uint8_t *)aligned_alloc(16, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src with non-zero test pattern
    uint16_t *src16 = (uint16_t *)src;
    for (int idx = 0; idx < num_pixels; idx++) {
        src16[idx] = (uint16_t)(0xFFFF & ((idx * 17) + 0x5A5A));
    }

    i = 0;
}