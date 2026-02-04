#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *pixels;
int stride;
int16_t *block;
int i;

void init_vars() {
    const size_t total_pixels_size = 256 * 1024 * 1024; // 256 MB
    pixels = (uint8_t*)aligned_alloc(64, total_pixels_size);
    if (!pixels) exit(1);

    block = (int16_t*)aligned_alloc(64, 8 * 8 * sizeof(int16_t));
    if (!block) exit(1);

    stride = 16;

    for (size_t idx = 0; idx < total_pixels_size; idx++) {
        pixels[idx] = (uint8_t)(idx % 256);
    }

    for (int idx = 0; idx < 8 * 8; idx++) {
        block[idx] = 0;
    }

    i = 0;
}