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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB of source data
    const int width = 1024; // Assumed width for 2D layout

    height = 16384; // Must be multiple of 4 due to >> 2 and 4*stride updates
    src_stride = width;
    dst_stride = width;

    size_t src_size = (size_t)height * src_stride;
    size_t dst_size = (size_t)height * dst_stride;

    src_buffer = aligned_alloc(32, src_size * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = (int16_t)(i & 0xFFFF);
    }
}