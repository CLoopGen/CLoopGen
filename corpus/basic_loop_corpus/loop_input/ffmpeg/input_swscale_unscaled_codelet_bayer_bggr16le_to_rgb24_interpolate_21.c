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
    width = 2048;
    src_stride = width * 2;
    dst_stride = width * 3;
    
    size_t src_size = (size_t)(width + 4) * src_stride;
    size_t dst_size = (size_t)(width + 4) * dst_stride;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer + (2 * src_stride) + 4;
    dst = dst_buffer + (2 * dst_stride) + 6;

    i = 2;
}