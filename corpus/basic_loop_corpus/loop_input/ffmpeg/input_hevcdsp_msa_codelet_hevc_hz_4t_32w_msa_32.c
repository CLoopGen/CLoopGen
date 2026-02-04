#include <stdint.h>
#include <stdlib.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t src_buffer[131072];
static int16_t dst_buffer[65536];

void init_vars() {
    src_stride = 16;
    dst_stride = 8;
    height = 8192;

    src = src_buffer;
    dst = dst_buffer;
}