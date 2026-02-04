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
    height = 100000;
    src_stride = 16;
    dst_stride = 8;

    size_t src_size = (size_t)(height)*2 * src_stride;
    size_t dst_size = (size_t)(height)*2 * dst_stride;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (int16_t*)calloc(dst_size, sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;
}