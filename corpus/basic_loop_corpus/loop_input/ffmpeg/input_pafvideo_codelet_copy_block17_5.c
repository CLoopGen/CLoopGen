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

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB total data
    const int element_size = 17; // At least 17 bytes per row (we access up to index 16)
    h = total_size / element_size;
    
    // Allocate buffers with padding to avoid out-of-bounds access
    dst_buffer = (uint8_t*)aligned_alloc(64, h * sizeof(uint8_t) * element_size);
    src_buffer = (uint8_t*)aligned_alloc(64, h * sizeof(uint8_t) * element_size);
    
    if (!dst_buffer || !src_buffer) {
        exit(1);
    }
    
    // Initialize source data
    for (size_t idx = 0; idx < h * element_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    
    // Set up strided access - allow full cache line utilization
    dstStride = element_size;
    srcStride = element_size;
    
    // Initialize pointers to start of buffers
    dst = dst_buffer;
    src = src_buffer;
}