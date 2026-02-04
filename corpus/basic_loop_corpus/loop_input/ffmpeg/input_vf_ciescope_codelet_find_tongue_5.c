#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t * pixels;
int w = 2048;
int linesize = 8192;
int row = 100;
int j;
int leftEdge = 0;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024;
    pixels = aligned_alloc(32, data_size);
    if (!pixels) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(uint16_t); i++) {
        pixels[i] = 0;
    }

    const int pixel_offset = row * linesize + (w - 1) * 4;
    if (pixel_offset * sizeof(uint16_t) < data_size) {
        pixels[pixel_offset + 0] = 1;
    }

    j = w - 1;
    leftEdge = 0;
}