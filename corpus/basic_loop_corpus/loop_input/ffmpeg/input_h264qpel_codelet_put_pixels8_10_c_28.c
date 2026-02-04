#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB target size

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    // Ensure line_size is multiple of 8 for alignment, and at least 8 bytes
    line_size = 16;
    h = DATA_SIZE / line_size;

    // Allocate buffers with proper size
    block_data = aligned_alloc(64, h * line_size);
    pixels_data = aligned_alloc(64, h * line_size);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers
    block = block_data;
    pixels = pixels_data;

    // Initialize pixel data to avoid undefined behavior
    for (int j = 0; j < h * line_size; j++) {
        pixels_data[j] = j & 0xFF;
    }
}

// Ensure cleanup if needed (though not required per spec)