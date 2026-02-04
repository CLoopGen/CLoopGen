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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    h = 1024 * 64;
    int width_bytes = 16;
    srcStride = width_bytes;
    dstStride = width_bytes;

    size_t src_size = (size_t)h * srcStride;
    size_t dst_size = (size_t)h * dstStride;

    src_buffer = (uint8_t*)aligned_alloc(16, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(16, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    for (size_t idx = 0; idx < dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}