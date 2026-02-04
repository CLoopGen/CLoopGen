#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t *src_tmp;
uint8_t *dst_tmp;
uint32_t loop_cnt;
uint32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int block_width_bytes = 32;
    const int blocks_per_row = 2;
    const int total_width = block_width_bytes * blocks_per_row;
    height = 1024;
    src_stride = total_width + 64;
    dst_stride = total_width + 64;

    size_t buffer_size = (size_t)height * (size_t)(src_stride > dst_stride ? src_stride : dst_stride);
    buffer_size += 32;

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0x5A, buffer_size);
    memset(dst_buffer, 0, buffer_size);

    src = src_buffer;
    dst = dst_buffer;

    src_tmp = NULL;
    dst_tmp = NULL;
    loop_cnt = 0;
    cnt = 0;
}