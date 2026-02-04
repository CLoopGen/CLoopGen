#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB for ~0.01 sec estimate

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Allocate buffers with sufficient size
    src_buffer = (uint8_t*)aligned_alloc(16, DATA_SIZE);
    dst_buffer = (uint8_t*)aligned_alloc(16, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set up pointers
    src = src_buffer;
    dst = dst_buffer;

    // Stride is 4 bytes since we're copying 32-bit values
    srcStride = 4;
    dstStride = 4;

    // Number of iterations: total bytes / 4 (since each iteration copies 4 bytes)
    h = DATA_SIZE / 4;

    // Ensure that the last access doesn't go out of bounds
    // Each iteration accesses 4 bytes, so we need at least h*4 bytes in buffers
}