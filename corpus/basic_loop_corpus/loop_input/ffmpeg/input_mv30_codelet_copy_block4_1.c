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

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int element_size = sizeof(uint32_t);
    const int elements_per_row = 1024;
    h = (DATA_SIZE / element_size + elements_per_row - 1) / elements_per_row;

    srcStride = elements_per_row * element_size;
    dstStride = elements_per_row * element_size;

    size_t total_bytes = (size_t)h * srcStride;

    src_buffer = aligned_alloc(32, total_bytes);
    dst_buffer = aligned_alloc(32, total_bytes);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_bytes; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
}