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

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB total data
#define ROWS 4096
#define ROW_WIDTH (DATA_SIZE / ROWS)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Allocate buffers with padding to avoid out-of-bounds access
    src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE + 8);
    dst_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE + 8);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t j = 0; j < DATA_SIZE + 8; j++) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }

    // Set up strided access parameters
    src = src_buffer;
    dst = dst_buffer;
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;
    h = ROWS;

    // Ensure that each iteration accesses within bounds:
    // Each iteration reads/writes 8 bytes (two 32-bit unaligned loads/stores)
    // So we require: src + h * srcStride + 8 <= src_buffer + DATA_SIZE + 8
    // Which is satisfied by our choice of ROW_WIDTH and ROWS
}