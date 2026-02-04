#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // ~64 MB for substantial workload
    src_stride = 8192; // Large stride to cover wide rows
    dst_stride = 8192;
    height = total_size / src_stride;

    if (height == 0) height = 1;
    if (src_stride <= 0) src_stride = 1;
    if (dst_stride <= 0) dst_stride = 1;

    src_buffer = aligned_alloc(32, (size_t)src_stride * (height > 0 ? height : 1));
    dst_buffer = aligned_alloc(32, (size_t)dst_stride * (height > 0 ? height : 1));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < (size_t)src_stride * height; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < (size_t)dst_stride * height; ++i) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    loop_cnt = 0;
}

__attribute__((constructor)) void setup() {
    init_vars();
}