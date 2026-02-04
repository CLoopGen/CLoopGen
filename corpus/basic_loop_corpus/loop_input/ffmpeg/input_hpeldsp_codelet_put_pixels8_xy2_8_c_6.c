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
int j;

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    // Allocate sufficient data to make loop run ~0.01 seconds
    // Based on typical performance, h around 1000-2000 and j=2 gives reasonable timing
    line_size = 1024;
    h = 1500;  // Inner loop runs 750 iterations per j

    // Total memory needed:
    // pixels: at least (h + 1) * line_size + 5 bytes (accessed up to pixels + 1 and line_size*(h+1))
    // block:  h * line_size + 4 bytes (written in steps of line_size, h times, with 32-bit writes)

    size_t pixels_size = (size_t)(h + 2) * line_size + 8;
    size_t block_size = (size_t)(h + 1) * line_size + 8;

    // Allocate aligned memory to avoid strict aliasing issues
    pixels_data = (uint8_t*)aligned_alloc(64, pixels_size);
    block_data = (uint8_t*)aligned_alloc(64, block_size);

    if (!pixels_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with deterministic pattern
    for (size_t i = 0; i < pixels_size; i++) {
        pixels_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < block_size; i++) {
        block_data[i] = 0;
    }

    // Set external pointers
    pixels = pixels_data;
    block = block_data;
}