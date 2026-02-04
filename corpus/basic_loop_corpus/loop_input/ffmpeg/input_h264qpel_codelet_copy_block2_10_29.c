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

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = 4;
    dstStride = 4;
    h = DATA_SIZE / 4;

    src_buffer = aligned_alloc(4, DATA_SIZE);
    dst_buffer = aligned_alloc(4, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}