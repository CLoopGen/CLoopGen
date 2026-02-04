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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int block_size = 8; // each copy handles 8 bytes via uint64_t
    const int rows = 16384;
    const int row_stride = block_size + 32; // ensure stride is larger than block to avoid overlap

    h = rows;
    srcStride = row_stride;
    dstStride = row_stride;

    size_t src_total = (size_t)(h - 1) * srcStride + block_size;
    size_t dst_total = (size_t)(h - 1) * dstStride + block_size;

    src_buffer = aligned_alloc(64, src_total);
    dst_buffer = aligned_alloc(64, dst_total);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_total; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    for (size_t idx = 0; idx < dst_total; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}