#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;
int a1;
int b1;
int a0;
int b0;

#define DATA_SIZE (128 * 1024 * 1024)  // ~128MB total data size
static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    // Allocate large buffers to ensure loop runs for ~0.01 seconds
    block_data = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    pixels_data = (uint8_t*)aligned_alloc(32, DATA_SIZE);

    if (!block_data || !pixels_data) {
        exit(1);
    }

    // Initialize pixel data with non-zero values
    for (size_t i = 0; i < DATA_SIZE; i++) {
        pixels_data[i] = (uint8_t)(i & 0xFF);
        block_data[i] = 0;
    }

    // Set line_size to a reasonable stride (e.g., 1920 for HD-like width)
    line_size = 1920;

    // Ensure h is even and such that we don't exceed buffer bounds
    // Each iteration uses 2 lines of pixels and block
    // Each line has at least 3 pixel elements accessed: [0], [1], [2]
    // So total lines used: h, and each line needs at least 3 bytes
    // We constrain h so that pixels + h * line_size + 2 < allocated size
    h = (DATA_SIZE / line_size) / 2 * 2;  // Make it even
    if (h > 10000) h = 10000;  // Cap to avoid excessive iterations
    h &= ~1;  // Ensure h is even

    // Initialize starting pointers within the allocated region
    pixels = pixels_data + 0;
    block = block_data + 0;

    // Initialize scalar variables
    a0 = 1;
    b0 = 2;
    a1 = 0;
    b1 = 0;
    i = 0;
}