#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
int32_t loop_cnt;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 << 20; // ~64 MB for balanced data size

    src_stride = 1024;
    dst_stride = 512;
    height = (total_data_size / (src_stride * 4)) * 4;

    size_t src_size = (height + 4) * (size_t)src_stride;
    size_t dst_size = (height + 4) * (size_t)dst_stride;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = (int16_t)(i & 0xFFFF);
    }
}