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
#define ROW_WIDTH 17

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int alignment = 16;

    src_buffer = aligned_alloc(alignment, DATA_SIZE);
    dst_buffer = aligned_alloc(alignment, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;

    dstStride = ROW_WIDTH;
    srcStride = ROW_WIDTH;

    h = (DATA_SIZE - 16) / dstStride; // ensures dst[16] is safe
}