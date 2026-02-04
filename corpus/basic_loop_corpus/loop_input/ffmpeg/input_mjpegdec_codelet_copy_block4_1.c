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

#define DATA_SIZE (64 << 20) // 64 MB of data

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int element_size = sizeof(uint32_t);
    const int elements_per_row = 1024;
    h = (DATA_SIZE / element_size) / elements_per_row;
    if (h == 0) h = 1;
    int total_elements = elements_per_row * h;

    src_buffer = aligned_alloc(32, total_elements * element_size);
    dst_buffer = aligned_alloc(32, total_elements * element_size);

    for (int i = 0; i < total_elements; i++) {
        ((uint32_t*)src_buffer)[i] = rand();
        ((uint32_t*)dst_buffer)[i] = 0;
    }

    srcStride = elements_per_row * element_size;
    dstStride = elements_per_row * element_size;

    src = src_buffer;
    dst = dst_buffer;
}