#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB for sufficient runtime (~0.01 sec target)
#define TAP_LENGTH 13 // from -2 to +10 inclusive

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE + TAP_LENGTH]; // extra padding for stencil access
static uint8_t internal_cm[512]; // larger than 256 to allow safe indexing with offset

void init_vars() {
    // Initialize strides
    dstStride = 1;
    srcStride = 1;

    // Set width to use most of the data, ensuring we don't go out of bounds
    // We need up to src[10*srcStride] so w must be <= available size - 10
    w = DATA_SIZE - 10;

    // Assign pointers to internal buffers
    dst = internal_dst;
    src = internal_src + 2; // shift so that src[-2] is valid (pointing to internal_src[0])
    cm = internal_cm + 256; // center cm at index 256 to allow negative offsets in indexing

    // Initialize src with non-zero test pattern
    for (size_t idx = 0; idx < DATA_SIZE + TAP_LENGTH; idx++) {
        internal_src[idx] = (uint8_t)((idx * 17) & 0xFF);
    }

    // Initialize cm lookup table: maps (weighted sum + 64) >> 7 to clamped byte value
    for (int j = -256; j < 256; j++) {
        int val = (j + 64) >> 7;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        internal_cm[j + 256] = (uint8_t)val;
    }

    // Initialize dst to zero
    memset(internal_dst, 0, DATA_SIZE);
}