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

#define DATA_SIZE (128 << 20)  // 128 MB total data size
#define BLOCK_HEIGHT 4096
#define LINE_WIDTH 32768

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    block_buffer = aligned_alloc(64, DATA_SIZE);
    pixels_buffer = aligned_alloc(64, DATA_SIZE);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        pixels_buffer[idx] = (uint8_t)(idx & 0xFF);
        block_buffer[idx] = 0;
    }

    line_size = LINE_WIDTH;
    h = BLOCK_HEIGHT;
    i = 0;

    block = block_buffer;
    pixels = pixels_buffer;
}