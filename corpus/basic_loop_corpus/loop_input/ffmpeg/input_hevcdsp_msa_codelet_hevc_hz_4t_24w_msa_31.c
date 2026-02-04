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
int16_t *dst_tmp;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    const int total_elements = 64 * 1024 * 1024;
    height = 16384;
    src_stride = 4096;
    dst_stride = 4096;

    src_buffer = aligned_alloc(32, total_elements * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, total_elements * sizeof(int16_t));

    src = src_buffer;
    dst = dst_buffer;
    dst_tmp = dst_buffer;

    for (int i = 0; i < total_elements; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = (int16_t)(i & 0xFFFF);
    }
}