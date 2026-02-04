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

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *block_buffer;
static uint8_t *pixels_buffer;

void init_vars() {
    line_size = 16; 
    h = DATA_SIZE / line_size;

    block_buffer = aligned_alloc(16, DATA_SIZE);
    pixels_buffer = aligned_alloc(16, DATA_SIZE);

    if (!block_buffer || !pixels_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    block = block_buffer;
    pixels = pixels_buffer;

    for (int j = 0; j < DATA_SIZE; j++) {
        pixels_buffer[j] = rand() & 0xFF;
    }
}