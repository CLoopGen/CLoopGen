#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_SIZE 32
#define NUM_ROWS (DATA_SIZE / ROW_SIZE)

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    dstStride = ROW_SIZE;
    srcStride = ROW_SIZE;
    h = NUM_ROWS;

    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
}