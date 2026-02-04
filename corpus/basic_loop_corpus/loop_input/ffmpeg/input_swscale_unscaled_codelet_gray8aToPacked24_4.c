#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int num_pixels;
uint8_t *palette;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // 64MB for ~0.01s runtime estimate

static uint8_t src_data[DATA_SIZE];
static uint8_t dst_data[DATA_SIZE * 3 / 2];  // worst case: each input byte produces 3 output bytes
static uint8_t palette_data[256 * 4];

void init_vars() {
    num_pixels = DATA_SIZE / 2;  // because index uses i << 1, so we need at most DATA_SIZE/2 pixels

    // Initialize palette: map each of 256 indices to RGBA values
    for (int idx = 0; idx < 256; idx++) {
        palette_data[idx * 4 + 0] = (uint8_t)(idx ^ 0x55);
        palette_data[idx * 4 + 1] = (uint8_t)(idx ^ 0xAA);
        palette_data[idx * 4 + 2] = (uint8_t)(idx ^ 0xF0);
        palette_data[idx * 4 + 3] = 0xFF;
    }

    // Initialize source data with valid indices into palette (0-255)
    for (int j = 0; j < DATA_SIZE; j++) {
        src_data[j] = (uint8_t)(j % 256);
    }

    // Set pointers
    src = src_data;
    dst = dst_data;
    palette = palette_data;
}