#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB total data
#define ROW_WIDTH (64)
#define ALIGNMENT 64

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int elements_per_row = ROW_WIDTH / sizeof(uint16_t);
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;
    h = (DATA_SIZE / ROW_WIDTH);
    
    // Allocate aligned memory to allow safe unaligned-64 access
    if (posix_memalign((void**)&src_buffer, ALIGNMENT, DATA_SIZE + ALIGNMENT) != 0 ||
        posix_memalign((void**)&dst_buffer, ALIGNMENT, DATA_SIZE + ALIGNMENT) != 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    // Initialize source data with known pattern
    for (int j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }

    // Ensure we don't exceed bounds in loop: each iteration accesses up to +12 bytes (4 * sizeof(uint16_t) = 8, then union l is 8-byte)
    // So we need at least 8 bytes beyond the second access -> ensure row width >= 16 bytes
    // Our ROW_WIDTH is 64 which satisfies this.

    // Adjust h if needed to prevent out-of-bounds at the last row
    // Each access uses base and base+8, so we require base+8+7 < allocated size per row
    // Since we use full stride-based advancement, and rows are independent, as long as ROW_WIDTH >= 16, we're safe.
    // We already have ROW_WIDTH=64, so it's safe.
}