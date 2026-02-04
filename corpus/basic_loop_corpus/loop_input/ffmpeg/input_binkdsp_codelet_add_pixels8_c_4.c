#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *restrict pixels;
int16_t *block;
int line_size;
int i;

#define BLOCK_SIZE (8 * 32768) // 8 elements per iteration, multiple iterations to achieve desired runtime

static uint8_t pixels_data[256 * 1024]; // 256 KB for pixels
static int16_t block_data[BLOCK_SIZE]; // ~128 KB for block

void init_vars() {
    line_size = 8; // ensures we stay within bounds when advancing pixels
    pixels = pixels_data;
    block = block_data;

    for (int j = 0; j < BLOCK_SIZE; j++) {
        block[j] = (int16_t)(j % 256 - 128);
    }

    for (size_t j = 0; j < sizeof(pixels_data); j++) {
        pixels_data[j] = (uint8_t)(j % 256);
    }
}