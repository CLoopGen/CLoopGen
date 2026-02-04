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
#define ELEMENT_SIZE sizeof(uint64_t)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int element_count = DATA_SIZE / ELEMENT_SIZE;
    h = element_count;

    srcStride = ELEMENT_SIZE;
    dstStride = ELEMENT_SIZE;

    src_buffer = aligned_alloc(8, DATA_SIZE);
    dst_buffer = aligned_alloc(8, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}