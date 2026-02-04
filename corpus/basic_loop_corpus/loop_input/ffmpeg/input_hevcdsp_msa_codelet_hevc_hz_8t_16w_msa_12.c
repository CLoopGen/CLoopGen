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

static uint8_t *src_data;
static int16_t *dst_data;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for balanced workload

    src_stride = 4096;
    dst_stride = 2048;
    height = (total_data_size / src_stride) & ~1; // Ensure divisible by 2

    if (height == 0) {
        height = 2;
    }

    size_t src_total = height * src_stride;
    size_t dst_total = height * dst_stride;

    src_data = aligned_alloc(32, src_total);
    dst_data = aligned_alloc(32, dst_total);

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_total; ++i) {
        src_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_total; ++i) {
        dst_data[i] = (int16_t)(i & 0xFFFF);
    }

    src = src_data;
    dst = dst_data;
}