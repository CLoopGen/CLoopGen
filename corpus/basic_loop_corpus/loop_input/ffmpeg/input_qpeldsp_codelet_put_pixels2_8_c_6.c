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

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    line_size = 2048; // 2KB per line
    h = DATA_SIZE / line_size;

    block_data = aligned_alloc(32, DATA_SIZE);
    pixels_data = aligned_alloc(32, DATA_SIZE);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        pixels_data[idx] = (uint8_t)(idx & 0xFF);
    }

    block = block_data;
    pixels = pixels_data;
}