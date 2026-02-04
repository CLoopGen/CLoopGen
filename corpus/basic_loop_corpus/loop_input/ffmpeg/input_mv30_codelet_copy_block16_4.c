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
static size_t row_size;

void init_vars() {
    row_size = 16; 
    h = 8000000; 
    total_size = row_size * h;

    src_buffer = aligned_alloc(64, total_size);
    dst_buffer = aligned_alloc(64, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
    srcStride = row_size;
    dstStride = row_size;
    i = 0;
}