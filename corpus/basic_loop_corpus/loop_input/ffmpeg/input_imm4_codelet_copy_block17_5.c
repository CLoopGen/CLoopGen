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

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_data_size = 128 << 20; // 128 MB
    const size_t row_size = 32; // At least 17 bytes per row (we access up to offset 16)
    h = total_data_size / row_size;
    if (h == 0) h = 1;

    dstStride = row_size;
    srcStride = row_size;

    dst_buffer = aligned_alloc(64, h * dstStride);
    src_buffer = aligned_alloc(64, h * srcStride);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < h * row_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
        dst_buffer[idx] = 0;
    }

    dst = dst_buffer;
    src = src_buffer;
    i = 0;
}