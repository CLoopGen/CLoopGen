#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec target)

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src2[DATA_SIZE];
static int16_t internal_tmp[DATA_SIZE / sizeof(int16_t) + 18]; // Extra padding for tmp[-16..+8*10]
static uint8_t internal_cm[256];

void init_vars() {
    const size_t tmp_size = DATA_SIZE / sizeof(int16_t) + 18;
    
    // Initialize parameters
    dstStride = 1;
    srcStride = 1;
    w = DATA_SIZE / 8;  // Each iteration writes 8 bytes to dst, so adjust loop count accordingly
    
    // Ensure w doesn't exceed safe bounds given tmp array size and indexing
    if (w > (tmp_size - 18)) {
        w = tmp_size - 18;
    }

    // Assign pointers into internal buffers with proper offsets
    dst = internal_dst;
    src2 = internal_src2;
    tmp = internal_tmp + 16; // Allow tmp[-16] to be valid (we use down to -16 effectively via -2*8)
    cm = internal_cm;

    // Initialize cm lookup table: identity mapping mod 256
    for (int idx = 0; idx < 256; idx++) {
        cm[idx] = (uint8_t)(idx & 0xFF);
    }

    // Initialize src2 with non-zero pattern
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        internal_src2[idx] = (uint8_t)((idx * 71) % 251);
    }

    // Initialize tmp with a smooth gradient pattern to simulate prediction residuals
    for (size_t idx = 0; idx < tmp_size; idx++) {
        internal_tmp[idx] = (int16_t)((idx * 13) % 511 - 255); // Range [-255, 256]
    }
}