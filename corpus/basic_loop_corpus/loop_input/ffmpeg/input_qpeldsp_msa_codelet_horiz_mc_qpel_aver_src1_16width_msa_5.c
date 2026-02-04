#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t loop_count;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for substantial runtime (~0.01 sec on modern CPU)
    const int block_height = 16384; // Large enough to ensure many iterations
    const int block_width = 16;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;

    src_buffer = aligned_alloc(32, total_data_size);
    dst_buffer = aligned_alloc(32, total_data_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}