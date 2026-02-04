#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int num_pixels;
uint8_t *palette;
int i;

void init_vars() {
    num_pixels = 64 * 1024 * 1024; // 64 million pixels (~256MB total data), adjust for ~0.01 sec on modern CPU

    src = (uint8_t *)aligned_alloc(32, num_pixels * sizeof(uint8_t));
    dst = (uint8_t *)aligned_alloc(32, num_pixels * sizeof(uint32_t));
    palette = (uint8_t *)aligned_alloc(32, 256 * sizeof(uint32_t));

    for (int j = 0; j < num_pixels; j++) {
        src[j] = rand() % 256; // valid index into palette
    }

    for (int j = 0; j < 256; j++) {
        ((uint32_t *)palette)[j] = rand() ^ (rand() << 16); // random 32-bit colors
    }
}