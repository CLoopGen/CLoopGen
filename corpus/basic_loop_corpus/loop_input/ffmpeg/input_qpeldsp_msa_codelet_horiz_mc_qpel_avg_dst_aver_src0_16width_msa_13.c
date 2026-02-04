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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for significant runtime (~0.01 sec on modern CPU)

    size_t src_height = 16384;
    size_t src_width = 1024;
    src_stride = (int32_t)src_width;
    height = (int32_t)src_height;

    size_t dst_height = src_height / 2;
    size_t dst_width = src_width / 2;
    dst_stride = (int32_t)dst_width;

    size_t src_buffer_size = src_height * src_stride;
    size_t dst_buffer_size = dst_height * dst_stride;

    src_buffer = aligned_alloc(32, src_buffer_size);
    dst_buffer = aligned_alloc(32, dst_buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_buffer_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_buffer_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}