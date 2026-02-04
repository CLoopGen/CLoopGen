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
    line_size = 16; // Each line has 16 bytes
    h = DATA_SIZE / line_size; // Number of iterations to process all data

    // Allocate memory for block and pixels
    block_data = aligned_alloc(16, DATA_SIZE);
    pixels_data = aligned_alloc(16, DATA_SIZE);

    // Initialize pointers
    block = block_data;
    pixels = pixels_data;

    // Ensure memory is initialized to avoid undefined behavior
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        pixels_data[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        block_data[idx] = 0;
    }
}