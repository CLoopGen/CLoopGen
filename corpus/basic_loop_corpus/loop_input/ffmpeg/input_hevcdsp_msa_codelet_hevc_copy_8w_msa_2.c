#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    height = 8192;
    src_stride = 8192;
    dst_stride = 8192;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    src_buffer = aligned_alloc(64, src_size);
    dst_buffer = aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(EXIT_FAILURE);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; ++i) {
        dst_buffer[i] = (int16_t)(i & 0x3FF);
    }
}