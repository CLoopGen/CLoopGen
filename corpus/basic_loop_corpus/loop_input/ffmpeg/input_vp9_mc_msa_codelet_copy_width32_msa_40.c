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
    const int32_t block_height = 8192;
    const int32_t block_width = 1024;
    height = block_height & (~7); 

    src_stride = block_width;
    dst_stride = block_width;

    size_t src_size = (size_t)(height + 8) * (size_t)src_stride;
    size_t dst_size = (size_t)(height + 8) * (size_t)dst_stride;

    src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    cnt = 0;
}