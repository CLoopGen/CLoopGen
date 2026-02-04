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
#define ROW_WIDTH (16 * sizeof(uint16_t)) // 32 bytes, covers 16 uint16_t elements
#define NUM_ROWS (DATA_SIZE / ROW_WIDTH)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int row_width = ROW_WIDTH;
    const int num_rows = NUM_ROWS;

    // Allocate buffers
    src_buffer = aligned_alloc(64, num_rows * row_width);
    dst_buffer = aligned_alloc(64, num_rows * row_width);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (int i = 0; i < num_rows * row_width; i++) {
        src_buffer[i] = rand() % 256;
    }

    // Set external variables
    src = src_buffer;
    dst = dst_buffer;
    srcStride = row_width;
    dstStride = row_width;
    h = num_rows;
    i = 0;
}