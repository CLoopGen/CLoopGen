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
    const size_t count = DATA_SIZE / element_size;

    src_buffer = aligned_alloc(16, count * element_size);
    dst_buffer = aligned_alloc(16, count * element_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < count; idx++) {
        ((uint16_t*)src_buffer)[idx] = (uint16_t)(idx * 0x9E37);
    }

    src = src_buffer;
    dst = dst_buffer;
    srcStride = element_size;
    dstStride = element_size;
    h = count;
    i = 0;
}