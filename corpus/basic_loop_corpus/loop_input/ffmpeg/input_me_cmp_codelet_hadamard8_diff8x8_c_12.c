#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int i;
int temp[64];

void init_vars() {
    // Allocate 64MB for src and dst to ensure meaningful computation time (~0.01s)
    size_t data_size = 64 * 1024 * 1024; // 64 MB
    src = (uint8_t *)aligned_alloc(32, data_size);
    dst = (uint8_t *)aligned_alloc(32, data_size);

    // Initialize with non-zero predictable pattern to avoid all-zero optimizations
    for (size_t idx = 0; idx < data_size; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
        dst[idx] = (uint8_t)((idx + 42) & 0xFF);
    }

    // Set stride to 8 bytes per row to match loop access pattern (i*stride + 0..7)
    stride = 8;

    // Initialize temp array to zero
    for (int j = 0; j < 64; j++) {
        temp[j] = 0;
    }

    // Initialize loop index
    i = 0;
}