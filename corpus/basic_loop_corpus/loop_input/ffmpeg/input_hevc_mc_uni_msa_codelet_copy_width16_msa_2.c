#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // 64 MB for substantial workload (~0.01 sec on modern CPU)
    const int block_height = 8;
    const int blocks_per_column = total_data_size / (block_height * 2 * 256); // estimate
    height = blocks_per_column * block_height;

    src_stride = 256;
    dst_stride = 256;

    size_t src_size = height * src_stride;
    size_t dst_size = height * dst_stride;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    cnt = 0;
}