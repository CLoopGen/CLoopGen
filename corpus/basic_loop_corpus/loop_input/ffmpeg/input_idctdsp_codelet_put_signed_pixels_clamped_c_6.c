#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *restrict pixels;
ptrdiff_t line_size;
int i;
int j;

#define BLOCK_SIZE (32768 * 8)
#define PIXELS_SIZE (32768 * (8 + 24))

static int16_t block_data[BLOCK_SIZE];
static uint8_t pixels_data[PIXELS_SIZE];

void init_vars() {
    block = block_data;
    pixels = pixels_data;
    line_size = 32; // Each row has 32 bytes, 8 used, rest padding
    i = 0;
    j = 0;

    // Initialize block data with values spanning the range
    for (int idx = 0; idx < BLOCK_SIZE; idx++) {
        block_data[idx] = (int16_t)((idx % 257) - 128); // Spread from -128 to 128
    }

    // Initialize pixels memory to zero
    for (int idx = 0; idx < PIXELS_SIZE; idx++) {
        pixels_data[idx] = 0;
    }
}