#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB of working data to ensure ~0.01s runtime
#define TMP_EXTRA 11  // tmp accesses up to index 10*8, so we need at least 11 elements ahead
#define STRIDE_DEFAULT 1

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src2[DATA_SIZE];
static int16_t internal_tmp[DATA_SIZE / sizeof(int16_t)];
static uint8_t internal_cm[256];  // cm is indexed by byte values, likely 0-255

void init_vars() {
    // Initialize strides
    dstStride = STRIDE_DEFAULT;
    srcStride = STRIDE_DEFAULT;

    // Set width such that we don't go out of bounds
    // Each iteration uses tmp[-2*8] to tmp[10*8], so we need at least 12*8 = 96 bytes before valid tmp
    // Also, we access up to dst[7*dstStride], so ensure dst has enough space
    // We assume each iteration moves dst, tmp, src2 by 1 element
    w = (DATA_SIZE / STRIDE_DEFAULT) - 10;  // leave room for tmp indexing with offset

    // Cap w to a safe value based on tmp buffer size in int16_t units
    int max_w_from_tmp = (sizeof(internal_tmp) / sizeof(int16_t)) - (10 * 8) - 1;
    if (w > max_w_from_tmp) {
        w = max_w_from_tmp;
    }

    // Ensure w is positive
    if (w <= 0) {
        w = 1;
    }

    // Assign pointers to internal buffers
    dst = internal_dst + 16;  // give some headroom for negative indexing if needed
    src2 = internal_src2;
    tmp = internal_tmp + (2 * 8);  // adjust so that tmp[-2*8] is valid
    cm = internal_cm;

    // Initialize cm lookup table (identity mapping for test)
    for (int idx = 0; idx < 256; idx++) {
        cm[idx] = (uint8_t)(idx & 0xFF);
    }

    // Initialize input data to non-zero to avoid trivial optimizations
    for (int j = 0; j < DATA_SIZE; j++) {
        internal_dst[j] = (uint8_t)(j % 251);
        internal_src2[j] = (uint8_t)(j % 199);
    }
    for (int j = 0; j < sizeof(internal_tmp)/sizeof(int16_t); j++) {
        internal_tmp[j] = (int16_t)(j % 100 - 50);
    }

    // Initialize scalar i to 0
    i = 0;
}