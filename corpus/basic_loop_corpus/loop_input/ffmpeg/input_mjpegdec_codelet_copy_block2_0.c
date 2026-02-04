#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
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
    srcStride = 2;
    dstStride = 2;
    h = DATA_SIZE / 2; // Each iteration copies 2 bytes

    src_buffer = aligned_alloc(32, DATA_SIZE);
    dst_buffer = aligned_alloc(32, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;
}