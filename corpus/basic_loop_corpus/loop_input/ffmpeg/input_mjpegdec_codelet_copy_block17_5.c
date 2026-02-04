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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int row_size = 17; // At least 17 bytes per row (access up to index 16)
    h = DATA_SIZE / row_size;
    if (h == 0) h = 1;
    
    srcStride = row_size;
    dstStride = row_size;

    size_t total_size = (size_t)h * row_size;

    src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx ^ 0xAA);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}