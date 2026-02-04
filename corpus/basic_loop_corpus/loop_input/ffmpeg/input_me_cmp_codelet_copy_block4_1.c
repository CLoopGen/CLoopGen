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
    const size_t element_size = sizeof(uint32_t);
    const size_t count = DATA_SIZE / element_size;

    // Ensure total size fits in address space and align to 4-byte boundary
    h = (int)count;

    src_buffer = aligned_alloc(4, DATA_SIZE);
    dst_buffer = aligned_alloc(4, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < count; ++idx) {
        uint32_t val = (uint32_t)(0xDEADBEEF ^ idx);
        ((uint32_t*)src_buffer)[idx] = val;
    }

    src = src_buffer;
    dst = dst_buffer;

    srcStride = element_size;
    dstStride = element_size;
}