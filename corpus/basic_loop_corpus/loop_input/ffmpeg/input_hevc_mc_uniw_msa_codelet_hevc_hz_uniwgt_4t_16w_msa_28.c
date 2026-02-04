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
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const int block_height = 1024;
    const int block_width = 16;

    src_stride = block_width + 16; // Allow padding
    dst_stride = block_width + 16;
    height = block_height;

    // Allocate larger buffers to allow safe access with strides and 4*stride jumps
    src_buffer = (uint8_t*)aligned_alloc(32, (size_t)(height + 8) * src_stride * sizeof(uint8_t));
    dst_buffer = (uint8_t*)aligned_alloc(32, (size_t)(height + 8) * dst_stride * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffers to zero (or any valid data)
    memset(src_buffer, 0x5A, (size_t)(height + 8) * src_stride);
    memset(dst_buffer, 0, (size_t)(height + 8) * dst_stride);

    // Set pointers to valid starting positions within buffers
    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = 0;
}