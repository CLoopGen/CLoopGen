#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int j;

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    line_size = 256; // reasonable stride, power of 2
    h = (data_size / line_size) / 4; // ensure enough rows for loop bounds

    // Adjust h to be at least 4 and even
    if (h < 4) h = 4;
    h = (h / 2) * 2;

    // Allocate sufficient data for pixels and block with padding
    size_t pixel_buffer_size = line_size * (h + 4); // extra rows for safety
    size_t block_buffer_size = line_size * (h + 4);

    pixels_data = (uint8_t*)calloc(pixel_buffer_size, 1);
    block_data = (uint8_t*)calloc(block_buffer_size, 1);

    if (!pixels_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with non-zero pattern to avoid all-zero edge cases
    for (size_t i = 0; i < pixel_buffer_size; i++) {
        pixels_data[i] = (uint8_t)(i ^ (i >> 8) ^ 0x5A);
    }
    for (size_t i = 0; i < block_buffer_size; i++) {
        block_data[i] = (uint8_t)((i ^ 0xA5) & 0xFF);
    }

    // Set pointers
    pixels = pixels_data;
    block = block_data;

    // Ensure initial offsets are within bounds
    j = 0;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
void cleanup_vars() {
    free(block_data);
    free(pixels_data);
}