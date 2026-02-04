#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride;
int8_t *filter;

static uint16_t src_data[256 * 1024]; // ~512KB input data
static int16_t dst_data[64 * 65536];  // large enough for writes
static int8_t filter_data[4] = {1, 8, -2, 1}; // example filter coefficients

void init_vars() {
    height = 4096;
    width = 64;
    srcstride = 64;

    // Ensure no out-of-bounds access: x-1 and x+2 must be valid
    // So we need at least width + 2 elements per row in src
    // Allocate extra padding on both sides
    uint16_t *padded_src = aligned_alloc(32, (width + 4) * height * sizeof(uint16_t));
    if (!padded_src) exit(1);

    src = padded_src + 1; // shift so that x-1 is valid starting at x=0

    for (int i = 0; i < height; i++) {
        uint16_t *row = &src[i * srcstride];
        for (int j = 0; j < width; j++) {
            row[j] = rand() % 4096;
        }
        // Pad neighbors
        row[-1] = row[0]; // left mirror
        row[width] = row[width - 1]; // right mirror
        row[width + 1] = row[width - 1]; // extra needed for x+2
    }

    dst = aligned_alloc(32, height * 64 * sizeof(int16_t));
    if (!dst) exit(1);
    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }

    filter = filter_data;
}