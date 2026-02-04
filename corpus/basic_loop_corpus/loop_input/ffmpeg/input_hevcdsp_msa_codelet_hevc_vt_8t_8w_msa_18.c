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

static uint8_t src_buffer[67108864]; // 64 MB
static int16_t dst_buffer[33554432]; // 64 MB as int16_t (2 bytes each)

void init_vars() {
    src_stride = 4096;
    dst_stride = 2048;
    height = 16384;

    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = 0;
}