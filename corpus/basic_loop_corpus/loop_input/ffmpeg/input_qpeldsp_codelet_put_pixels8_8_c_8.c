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

#define DATA_SIZE (128 << 20) // 128 MB total data size

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    // Allocate large buffers to ensure loop runs for ~0.01 seconds
    block_buffer = aligned_alloc(32, DATA_SIZE);
    pixels_buffer = aligned_alloc(32, DATA_SIZE);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize all accessible variables
    block = block_buffer;
    pixels = pixels_buffer;
    line_size = 4; // Each iteration advances by 4 bytes
    h = DATA_SIZE / line_size / 2; // Ensure we don't overflow buffer in loop (each iteration writes 8 bytes to block and reads from two 4-byte pixel locations)
}