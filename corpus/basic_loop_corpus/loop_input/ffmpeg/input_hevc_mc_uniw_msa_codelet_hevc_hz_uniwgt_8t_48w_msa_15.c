#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 64 * 1024 * 1024; // 64 MB

void init_vars() {
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    src_stride = 1024;
    dst_stride = 1024;
    loop_cnt = 64;
}