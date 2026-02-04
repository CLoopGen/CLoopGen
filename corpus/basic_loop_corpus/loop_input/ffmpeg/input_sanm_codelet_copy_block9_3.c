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

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB
    const int element_size = 9; // We access up to index 8

    h = total_data_size / element_size;
    if (h == 0) h = 1;

    srcStride = element_size;
    dstStride = element_size;

    size_t src_size = (size_t)h * (size_t)srcStride;
    size_t dst_size = (size_t)h * (size_t)dstStride;

    src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}