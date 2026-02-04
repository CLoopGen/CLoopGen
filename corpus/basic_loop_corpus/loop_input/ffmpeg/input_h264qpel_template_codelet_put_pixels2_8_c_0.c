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

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    line_size = 2048; // 2KB per line
    h = DATA_SIZE / line_size;
    
    block_buffer = aligned_alloc(32, h * line_size);
    pixels_buffer = aligned_alloc(32, h * line_size);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    block = block_buffer;
    pixels = pixels_buffer;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < line_size; x++) {
            pixels_buffer[y * line_size + x] = rand() & 0xFF;
        }
    }
}