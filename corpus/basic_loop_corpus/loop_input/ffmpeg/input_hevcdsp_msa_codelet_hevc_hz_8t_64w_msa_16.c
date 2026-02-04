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

static uint8_t src_buffer[16777216]; // 16 MB
static int16_t dst_buffer[8388608];  // 16 MB (since int16_t is half size)

void init_vars() {
    src = src_buffer;
    src_stride = 4096;
    dst = dst_buffer;
    dst_stride = 2048;
    height = 4096;
}