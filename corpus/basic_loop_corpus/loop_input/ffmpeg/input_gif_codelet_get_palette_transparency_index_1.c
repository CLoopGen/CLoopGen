#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *palette;
int transparent_color_index;
unsigned int i;
unsigned int smallest_alpha;

void init_vars() {
    smallest_alpha = 255;
    transparent_color_index = -1;
    palette = (uint32_t*)malloc(256 * sizeof(uint32_t));
    if (!palette) {
        exit(1);
    }
    for (unsigned int idx = 0; idx < 256; idx++) {
        uint8_t alpha = (idx * 17 + 42) % 256;
        palette[idx] = ((uint32_t)alpha << 24) | (idx << 16) | (idx << 8) | idx;
    }
}