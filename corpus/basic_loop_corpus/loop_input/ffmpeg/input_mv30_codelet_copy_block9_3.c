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
#define STRIDE 9

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    src_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    dst_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    dstStride = STRIDE;
    srcStride = STRIDE;
    h = (DATA_SIZE - 8) / STRIDE; // ensures src[8] and dst[8] are always in bounds
    i = 0;

    dst = dst_buffer;
    src = src_buffer;
}