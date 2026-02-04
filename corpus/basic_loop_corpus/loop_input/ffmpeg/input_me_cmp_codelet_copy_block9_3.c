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
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    const size_t row_size = 9; // At least 9 bytes per row (access up to index 8)
    h = data_size / row_size;
    if (h == 0) h = 1;

    dstStride = row_size;
    srcStride = row_size;

    dst_buffer = aligned_alloc(64, (size_t)h * dstStride);
    src_buffer = aligned_alloc(64, (size_t)h * srcStride);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int row = 0; row < h; row++) {
        uint8_t *d = dst_buffer + row * dstStride;
        const uint8_t *s = src_buffer + row * srcStride;
        for (size_t k = 0; k < row_size; k++) {
            ((uint8_t*)s)[k] = (uint8_t)(k + row);
        }
    }

    dst = dst_buffer;
    src = src_buffer;
}