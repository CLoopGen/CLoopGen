#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *restrict block;
uint8_t *pixels;
ptrdiff_t line_size;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of total pixel data

static uint8_t *pixels_buffer;
static int16_t *block_buffer;

void init_vars() {
    line_size = 16; // stride of 16 bytes per row

    // Allocate large buffers to ensure loop takes measurable time
    pixels_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    block_buffer = (int16_t*)aligned_alloc(32, DATA_SIZE * sizeof(int16_t));

    if (!pixels_buffer || !block_buffer) {
        exit(1);
    }

    // Initialize pixel data with known values
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        pixels_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Set the initial pointers
    pixels = pixels_buffer;
    block = block_buffer;
}