#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB total data size
#define SRC_PADDING 11 // To cover access from -2 to +10 in the convolution

static uint8_t internal_src[DATA_SIZE + SRC_PADDING];
static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_cm[256];

void init_vars() {
    // Initialize constants
    h = DATA_SIZE / 8; // Each iteration processes 8 bytes

    // Stride is 8 bytes per row for dst and src
    dstStride = 8;
    srcStride = 8;

    // Point to internal buffers
    src = internal_src + 2; // Allow for negative indexing down to -2
    dst = internal_dst;

    cm = internal_cm;

    // Initialize cm lookup table: clamp convolved result to [0,255]
    for (int j = 0; j < 256; j++) {
        cm[j] = (uint8_t)j;
    }

    // Initialize src with non-zero test pattern within valid range
    for (size_t j = 0; j < DATA_SIZE + SRC_PADDING; j++) {
        internal_src[j] = (uint8_t)((j * 17 + 0x55) & 0xFF);
    }

    // Initialize dst to zero
    memset(internal_dst, 0, DATA_SIZE);
}