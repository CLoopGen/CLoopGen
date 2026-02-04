#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static const size_t total_data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    src_stride = 2048;
    dst_stride = 2048;
    height = (total_data_size / src_stride) & ~1; // Ensure divisible by 2 for loop logic

    if ((src_buffer = aligned_alloc(32, total_data_size)) == NULL) abort();
    if ((dst_buffer = aligned_alloc(32, total_data_size)) == NULL) abort();

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}