#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_cm[512]; // cm is typically a clipping mask with 256+ entries

void init_vars() {
    // Initialize strides: assume processing 9x9 block of pixels with some stride padding
    dstStride = 16;
    srcStride = 16;
    
    // Set height such that we don't overflow the buffer
    // Each iteration consumes src[0..8] and writes dst[0..7]
    // We need at least 9 rows in src and 8 rows in dst
    h = (TOTAL_ELEMENTS / (srcStride * 9)) > 1000 ? 1000 : (TOTAL_ELEMENTS / (srcStride * 9));
    if (h == 0) h = 1;

    // Ensure we have enough data to avoid out-of-bounds access
    size_t min_src_needed = h * srcStride + 8; // because we read up to src[8]
    size_t min_dst_needed = h * dstStride + 8; // because we write up to dst[7]

    if (min_src_needed > TOTAL_ELEMENTS || min_dst_needed > TOTAL_ELEMENTS) {
        // Adjust h to fit within allocated memory
        h = (TOTAL_ELEMENTS - 8) / srcStride;
    }

    // Assign pointers to internal buffers
    dst = internal_dst;
    src = internal_src;
    cm = internal_cm;

    // Initialize cm: standard clip table [0,255], but allow some headroom
    for (int idx = 0; idx < 512; idx++) {
        internal_cm[idx] = (idx < 256) ? 0 : ((idx > 511) ? 255 : (uint8_t)(idx - 256));
    }

    // Initialize src with non-zero values to ensure meaningful computation
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < srcStride; col++) {
            internal_src[row * srcStride + col] = (uint8_t)(row * 3 + col * 7 + 1);
        }
    }

    // Initialize dst to zero
    memset(internal_dst, 0, h * dstStride);

    // Initialize loop index
    i = 0;
}