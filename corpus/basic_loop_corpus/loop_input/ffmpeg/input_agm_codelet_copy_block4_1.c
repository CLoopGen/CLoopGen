#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
int i;

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = 4;
    dstStride = 4;
    h = DATA_SIZE / 4;

    src_buffer = aligned_alloc(16, DATA_SIZE);
    dst_buffer = aligned_alloc(16, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}