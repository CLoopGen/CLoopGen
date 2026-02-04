#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

#define DATA_SIZE (128 << 20)  // 128 MB total data size

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    // Allocate buffers with sufficient size
    block_buffer = aligned_alloc(64, DATA_SIZE);
    pixels_buffer = aligned_alloc(64, DATA_SIZE);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize variables
    block = block_buffer;
    pixels = pixels_buffer;
    line_size = 1024;  // Each line has 1024 bytes
    h = (DATA_SIZE / line_size) / 2;  // Ensure we don't exceed buffer size when accessing two 32-bit values per row

    // Make sure each row accessed fits within the allocated space
    if (h * line_size + 8 > DATA_SIZE) {
        h = (DATA_SIZE - 8) / line_size;
    }

    // Initialize pixel data to prevent undefined behavior
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        pixels_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        block_buffer[idx] = 0;
    }
}