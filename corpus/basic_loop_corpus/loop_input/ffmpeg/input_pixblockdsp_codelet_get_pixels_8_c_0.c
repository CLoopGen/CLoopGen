#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *restrict block;
uint8_t *pixels;
ptrdiff_t stride;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of pixel data to ensure ~0.01s runtime

static uint8_t *pixels_buffer;
static int16_t *block_buffer;

void init_vars() {
    stride = 16; // Stride greater than 8 to simulate row stride in image-like data

    // Allocate pixels buffer: needs at least 8 rows * stride, each row accessed with 8 elements
    pixels_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!pixels_buffer) exit(1);

    // Total blocks needed: DATA_SIZE / (stride * 8), but we limit by our loop count per call
    // We assume loop() is called repeatedly or processes a portion
    block_buffer = (int16_t*)aligned_alloc(32, DATA_SIZE * 2); // int16_t is 2x size
    if (!block_buffer) exit(1);

    // Initialize pixel data to non-zero for meaningful processing
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        pixels_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Set initial pointers
    pixels = pixels_buffer;
    block = block_buffer;
}