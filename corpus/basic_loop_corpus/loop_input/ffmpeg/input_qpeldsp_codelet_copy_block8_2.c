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

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int element_size = sizeof(uint64_t);
    const int elements_per_row = 1024;
    const int row_count = DATA_SIZE / (elements_per_row * element_size);
    
    h = row_count;
    srcStride = elements_per_row * element_size;
    dstStride = elements_per_row * element_size;

    // Allocate buffers with proper alignment for unaligned_64 access
    if (posix_memalign((void**)&src_buffer, sizeof(uint64_t), DATA_SIZE) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&dst_buffer, sizeof(uint64_t), DATA_SIZE) != 0) {
        exit(1);
    }

    // Initialize source data
    for (int j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = rand() & 0xFF;
    }

    // Set pointers to start of buffers
    src = src_buffer;
    dst = dst_buffer;
}