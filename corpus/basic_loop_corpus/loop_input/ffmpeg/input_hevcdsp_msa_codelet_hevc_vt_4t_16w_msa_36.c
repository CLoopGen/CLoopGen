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

static uint8_t src_data[67108864]; // ~64 MB
static int16_t dst_data[67108864]; // ~128 MB (each int16_t is 2 bytes)

void init_vars() {
    src_stride = 16384;
    dst_stride = 16384;
    height = 16384;

    src = src_data;
    dst = dst_data;

    loop_cnt = 0;
}