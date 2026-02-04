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
    const int element_size = 9; // at least 9 bytes for access at index 8
    h = DATA_SIZE / element_size;
    if (h == 0) h = 1;

    srcStride = element_size;
    dstStride = element_size;

    src_buffer = aligned_alloc(64, (size_t)h * srcStride);
    dst_buffer = aligned_alloc(64, (size_t)h * dstStride);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < h * srcStride; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
}