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
    const int32_t total_elements_src = 64 << 20; // ~64 MB of source data
    const int32_t total_elements_dst = 64 << 20; // ~64 MB of destination data

    src_buffer = (uint8_t*)aligned_alloc(32, total_elements_src * sizeof(uint8_t));
    dst_buffer = (int16_t*)aligned_alloc(32, total_elements_dst * sizeof(int16_t));

    for (int i = 0; i < total_elements_src; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (int i = 0; i < total_elements_dst; i++) {
        dst_buffer[i] = rand() & 0xFFFF;
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = 1;
    dst_stride = 1;

    height = 4 * (1 << 20); // ensures loop runs about 1M iterations (>>2 => 250k)
    loop_cnt = height >> 2;
}