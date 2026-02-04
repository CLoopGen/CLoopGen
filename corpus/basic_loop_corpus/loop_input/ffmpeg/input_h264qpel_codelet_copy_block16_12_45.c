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

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_WIDTH (16 * sizeof(uint16_t)) // 32 bytes per row access
#define ROWS_PER_CHUNK 1

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int total_rows = DATA_SIZE / ROW_WIDTH;
    const size_t buffer_size = (size_t)total_rows * ROW_WIDTH;

    // Allocate buffers
    src_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t j = 0; j < buffer_size; j++) {
        src_buffer[j] = rand() % 256;
    }

    // Set external variables
    src = src_buffer;
    dst = dst_buffer;
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;
    h = total_rows;
    i = 0;
}