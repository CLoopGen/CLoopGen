#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width;
uint8_t *src_tmp;
int16_t *dst_tmp;
int32_t loop_cnt;
int32_t cnt;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    width = 1024;
    height = 512;
    src_stride = 1024;
    dst_stride = 1024;

    size_t src_size = (size_t)src_stride * height;
    size_t dst_size = (size_t)dst_stride * height * sizeof(int16_t);

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (int16_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size / sizeof(int16_t); i++) {
        dst_buffer[i] = (int16_t)(i & 0x3FF);
    }

    src = src_buffer;
    dst = dst_buffer;
}