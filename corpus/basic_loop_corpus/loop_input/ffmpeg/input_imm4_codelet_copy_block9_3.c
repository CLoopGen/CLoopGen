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
    const int element_size = 9; // We access up to index 8, so need at least 9 bytes per element
    const int num_elements = DATA_SIZE / element_size;
    
    src_buffer = (uint8_t*)aligned_alloc(64, num_elements * element_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, num_elements * element_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < num_elements * element_size; j++) {
        src_buffer[j] = rand() & 0xFF;
    }

    dstStride = element_size;
    srcStride = element_size;
    h = num_elements;
    i = 0;

    dst = dst_buffer;
    src = src_buffer;
}