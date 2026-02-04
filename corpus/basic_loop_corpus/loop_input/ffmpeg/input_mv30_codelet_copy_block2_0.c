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
    const size_t element_size = sizeof(uint16_t);
    const size_t num_elements = DATA_SIZE / element_size;
    h = (int)num_elements;

    src_buffer = aligned_alloc(16, DATA_SIZE);
    dst_buffer = aligned_alloc(16, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    dstStride = sizeof(uint16_t);
    srcStride = sizeof(uint16_t);

    src = src_buffer;
    dst = dst_buffer;
}