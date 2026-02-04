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

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    line_size = 1920;
    h = 300;

    size_t total_size = (size_t)line_size * (size_t)h;

    block_buffer = aligned_alloc(64, total_size);
    pixels_buffer = aligned_alloc(64, total_size);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        pixels_buffer[idx] = (uint8_t)(idx & 0xFF);
        block_buffer[idx] = 0;
    }

    block = block_buffer;
    pixels = pixels_buffer;
}