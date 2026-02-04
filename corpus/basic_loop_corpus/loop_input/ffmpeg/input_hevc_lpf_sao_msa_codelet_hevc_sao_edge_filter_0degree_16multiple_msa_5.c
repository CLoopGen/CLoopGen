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
uint8_t *dst_ptr;
uint8_t *src_minus1;
int32_t v_cnt;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;

void init_vars() {
    width = 1024;
    height = 512;
    src_stride = 1024;
    dst_stride = 1024;

    size_t src_size = (size_t)(src_stride) * (height + 3);
    size_t dst_size = (size_t)(dst_stride) * (height + 3);

    internal_src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    internal_dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        exit(1);
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;

    for (size_t i = 0; i < src_size; ++i) {
        internal_src_buffer[i] = (uint8_t)(i % 256);
    }
    for (size_t i = 0; i < dst_size; ++i) {
        internal_dst_buffer[i] = 0;
    }

    dst_ptr = NULL;
    src_minus1 = NULL;
    v_cnt = 0;
}