#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    const size_t buffer_size = (size_t)block_height * block_width;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height & ~0x3; // Ensure height is multiple of 4

    src_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}