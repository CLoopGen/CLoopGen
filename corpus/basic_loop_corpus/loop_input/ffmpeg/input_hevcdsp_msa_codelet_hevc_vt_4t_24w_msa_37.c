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

static uint8_t src_data[1 << 20]; // 1MB of source data
static int16_t dst_data[1 << 19];  // 512KB of destination data (each int16_t is half the size of uint8_t for same element count)

void init_vars() {
    src_stride = 1024;
    dst_stride = 512;
    height = 1024;

    src = src_data;
    dst = dst_data;
}