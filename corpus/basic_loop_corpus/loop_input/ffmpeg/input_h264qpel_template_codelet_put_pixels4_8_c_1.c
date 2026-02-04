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

#define DATA_SIZE (128 << 20)  // 128 MB

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    line_size = 1920;  // Common video line width, ensures alignment and realistic access
    h = DATA_SIZE / line_size;
    if (h * line_size > DATA_SIZE) {
        h = DATA_SIZE / line_size;
    }

    block_buffer = aligned_alloc(64, h * line_size);
    pixels_buffer = aligned_alloc(64, h * line_size);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < h * line_size; idx++) {
        pixels_buffer[idx] = (uint8_t)(idx & 0xFF);
        block_buffer[idx] = 0;
    }

    block = block_buffer;
    pixels = pixels_buffer;
}