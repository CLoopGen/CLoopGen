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
int i;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data
static uint8_t *block_base;
static uint8_t *pixels_base;

void init_vars() {
    line_size = 16; // Each row is 16 bytes wide
    size_t height = DATA_SIZE / line_size;

    // Allocate sufficient memory to allow 16 iterations with line_size step
    block_base = aligned_alloc(16, (16 + 1) * line_size);
    pixels_base = aligned_alloc(16, (16 + 1) * line_size);

    if (!block_base || !pixels_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers to valid regions within allocated memory
    block = block_base;
    pixels = pixels_base;

    // Initialize pixel data with known values
    for (size_t idx = 0; idx < (16 * line_size); idx++) {
        pixels_base[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < (16 * line_size); idx++) {
        block_base[idx] = 0;
    }
}