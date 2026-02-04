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
    const int element_size = sizeof(uint16_t);
    const int elements_per_row = 1024;
    const int rows = (DATA_SIZE + elements_per_row * element_size - 1) / (elements_per_row * element_size);
    
    src_buffer = aligned_alloc(16, rows * elements_per_row * element_size);
    dst_buffer = aligned_alloc(16, rows * elements_per_row * element_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < rows * elements_per_row; i++) {
        ((uint16_t*)src_buffer)[i] = (uint16_t)(i * 0x9E37);
    }

    src = src_buffer;
    dst = dst_buffer;
    srcStride = elements_per_row * element_size;
    dstStride = elements_per_row * element_size;
    h = rows;
    i = 0;
}