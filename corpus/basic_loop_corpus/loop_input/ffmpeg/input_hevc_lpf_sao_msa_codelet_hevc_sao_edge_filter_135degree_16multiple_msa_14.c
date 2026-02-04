#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t dst_stride;
uint8_t *src;
int32_t src_stride;
int32_t width;
int32_t height;
uint8_t *src_orig;
uint8_t *dst_orig;
int32_t v_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 1024;
    height = 256;
    src_stride = 1024;
    dst_stride = 1024;

    size_t src_size = (size_t)(src_stride * height);
    size_t dst_size = (size_t)(dst_stride * height);

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

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
    src_orig = NULL;
    dst_orig = NULL;
    v_cnt = 0;
}