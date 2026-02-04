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
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Set dimensions for ~100ms of work: aim for moderate cache pressure
    // Each iteration processes 4 rows of source and 4 rows of destination
    // Assume typical stride around 1024-4096, pick 2048 as representative
    const int32_t effective_width = 2048;
    src_stride = effective_width;
    dst_stride = effective_width;
    height = 16384;  // 16k rows -> loop_cnt = 16384 / 4 = 4096 iterations

    total_src_size = (size_t)(height + 4) * (size_t)src_stride;  // extra padding
    total_dst_size = (size_t)(height + 4) * (size_t)dst_stride;

    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with non-zero predictable pattern
    for (size_t i = 0; i < total_src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    // Point src and dst to valid regions within allocated buffers
    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = height >> 2;
}