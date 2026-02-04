#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t loop_count;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    src_stride = block_width;
    dst_stride = block_width;
    height = block_height & (~3); // Ensure divisible by 4

    size_t src_size = (size_t)block_height * src_stride;
    size_t dst_size = (size_t)block_height * dst_stride;

    src_buffer = aligned_alloc(64, src_size);
    dst_buffer = aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}