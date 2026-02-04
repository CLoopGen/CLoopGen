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

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)
    
    src_buffer = (uint8_t*)aligned_alloc(32, input_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, input_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t idx = 0; idx < input_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 251);
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = 1024;
    dst_stride = 1024;

    width = 512;

    i = 0;
}