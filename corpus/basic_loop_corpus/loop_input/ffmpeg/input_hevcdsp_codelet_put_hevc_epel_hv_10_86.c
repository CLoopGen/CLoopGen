#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 256;
int width = 256;

int16_t *dst;
int8_t *filter;
int16_t *tmp;

int x;
int y;

void init_vars() {
    // Allocate dst and tmp with padding to prevent out-of-bounds access
    // The loop accesses: tmp[x - 64], tmp[x], tmp[x + 64], tmp[x + 128]
    // So we need at least 64 elements before the first valid x=0, and 128 after
    const int pre_offset = 64;
    const int post_offset = 128;
    const int total_width = width + pre_offset + post_offset;
    const int total_size = total_width * height;

    tmp = (int16_t*)aligned_alloc(64, sizeof(int16_t) * total_size);
    dst = (int16_t*)aligned_alloc(64, sizeof(int16_t) * total_size);

    filter = (int8_t*)aligned_alloc(64, sizeof(int8_t) * 4);

    // Initialize filter with non-zero values to make computation meaningful
    filter[0] = 15;
    filter[1] = 35;
    filter[2] = 25;
    filter[3] = 10;  // Sum ~85, right shift by 6 => scale down

    // Initialize tmp with known values
    for (int i = 0; i < total_size; i++) {
        tmp[i] = (int16_t)(i % 256);
    }

    // Zero-initialize output
    for (int i = 0; i < total_size; i++) {
        dst[i] = 0;
    }
}