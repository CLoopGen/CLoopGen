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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;

void init_vars() {
    total_size = 128 * 1024 * 1024; // 128 MB

    src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    dstStride = 8;
    srcStride = 8;
    h = total_size / 8;

    dst = dst_buffer;
    src = src_buffer;
}