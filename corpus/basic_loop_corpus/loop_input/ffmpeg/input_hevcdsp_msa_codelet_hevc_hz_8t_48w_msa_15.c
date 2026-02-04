#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t src_buffer[16777216]; // 16MB buffer for src
static int16_t dst_buffer[8388608];  // 16MB buffer for dst (each int16_t is 2 bytes)

void init_vars() {
    const uint32_t elements_per_row = 4096;
    height = 4096;

    src_stride = elements_per_row;
    dst_stride = elements_per_row / 2;

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < sizeof(src_buffer); i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    for (size_t i = 0; i < sizeof(dst_buffer) / sizeof(int16_t); i++) {
        dst_buffer[i] = 0;
    }
}