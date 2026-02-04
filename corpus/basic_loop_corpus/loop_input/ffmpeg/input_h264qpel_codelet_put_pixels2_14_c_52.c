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

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    line_size = 4096; // 4KB per line
    h = DATA_SIZE / line_size;

    block_data = aligned_alloc(32, DATA_SIZE);
    pixels_data = aligned_alloc(32, DATA_SIZE);

    block = block_data;
    pixels = pixels_data;

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        pixels_data[i] = rand() & 0xFF;
    }
}