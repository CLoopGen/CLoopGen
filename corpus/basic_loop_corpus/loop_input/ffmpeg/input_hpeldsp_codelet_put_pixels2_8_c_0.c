#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    line_size = 2048;
    h = 65536 / line_size;
    if (h == 0) h = 1;
    size_t total_size = (size_t)h * line_size;

    block_buffer = aligned_alloc(32, total_size);
    pixels_buffer = aligned_alloc(32, total_size);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        pixels_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    block = block_buffer;
    pixels = pixels_buffer;
}