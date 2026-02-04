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

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB target data size

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    // Allocate aligned memory to ensure no aliasing issues and proper access
    block_data = aligned_alloc(64, DATA_SIZE);
    pixels_data = aligned_alloc(64, DATA_SIZE);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with predictable pattern
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        pixels_data[idx] = (uint8_t)(idx & 0xFF);
        block_data[idx] = 0;
    }

    // Set external pointers
    block = block_data;
    pixels = pixels_data;

    // Each iteration processes two 64-bit values (16 bytes total)
    // Ensure we don't exceed buffer bounds: each row must be at least 8 + 8 = 16 bytes
    const int min_row_size = 16;
    
    // Choose line_size as multiple of 16 for alignment, leave room for h rows
    line_size = 64; // reasonable stride
    
    // Maximum number of rows without overflow: DATA_SIZE / line_size
    // But also ensure that within each row, offset 4*sizeof(uint16_t)=8 is valid
    h = DATA_SIZE / line_size;

    // Clip h to ensure last access stays in bounds
    if (h > (DATA_SIZE - 8) / line_size) {
        h = (DATA_SIZE - 8) / line_size;
    }

    // Final safeguard
    if (h <= 0) {
        h = 1;
        line_size = 8;
    }
}