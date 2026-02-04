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
#define ROW_WIDTH (64 * sizeof(uint16_t))
#define NUM_ROWS 2048

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;
    h = NUM_ROWS;
    i = 0;

    size_t total_size = (size_t)srcStride * (h + 1);
    src_buffer = aligned_alloc(64, total_size);
    dst_buffer = aligned_alloc(64, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}