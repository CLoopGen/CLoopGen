#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define WIDTH (1920)
#define HEIGHT (1080)
#define STRIDE_ALIGNMENT 64

static uint8_t internal_dst[HEIGHT][WIDTH + STRIDE_ALIGNMENT]; // Extra space for alignment and safety
static int16_t internal_tmp_buffer[(HEIGHT + 20) * WIDTH]; // Extra padding for -2*8 to +10*8 lookups
static uint8_t internal_cm[1 << 10]; // cm indexed by 10-bit shift, so size 1024

void init_vars() {
    // Set reasonable dimensions
    w = WIDTH;

    // Ensure dstStride is aligned and large enough
    dstStride = WIDTH + STRIDE_ALIGNMENT;

    // Align dst to a cache line boundary within internal_dst
    dst = (uint8_t*)(((uintptr_t)internal_dst[0] + STRIDE_ALIGNMENT - 1) & ~(STRIDE_ALIGNMENT - 1));

    // tmp needs to allow indexing from -2*8 to (w-1 + 10*8), so we offset it
    tmp = internal_tmp_buffer + 16; // Reserve first 16 elements for negative indices

    // Initialize tmp with non-zero values to avoid trivial optimization
    for (int idx = 0; idx < (HEIGHT + 20) * WIDTH; idx++) {
        internal_tmp_buffer[idx] = (int16_t)(idx % 256);
    }

    // Initialize cm lookup table
    for (int idx = 0; idx < (1 << 10); idx++) {
        internal_cm[idx] = (uint8_t)((idx * 17) % 256);
    }
    cm = internal_cm;

    // Initialize dst with non-zero values
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dst[y * dstStride + x] = (uint8_t)(x ^ y);
        }
    }

    // Initialize loop index
    i = 0;
}