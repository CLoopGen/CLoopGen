#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    width = 1 << 23; // Approximately 8M iterations, should take ~0.01s with optimization
    src_stride = 256;
    dst_stride = 256;
    
    total_src_size = (1 + 1) * src_stride + 2 * ((width / 2) * 2) + 32; // Over-allocate for safety
    total_dst_size = (1 + 1) * dst_stride + 6 * (width / 2) + 32;

    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < total_src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < total_dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    i = 0;
}