#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
uint8_t height;
uint8_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Aim for approximately 64MB of source data to achieve ~0.01s runtime on modern CPUs
    const size_t target_data_size = 64 * 1024 * 1024;
    // Assume effective processing of 8 rows at a time, each row roughly aligned to stride
    // Estimate reasonable height and stride to hit target data size

    // Let's choose a stride around 4K to simulate realistic image-like data
    src_stride = 4096;
    height = (target_data_size / src_stride) & ~7; // Make divisible by 8 due to >>3
    if (height == 0) height = 8;
    else if (height > 255) height = 255; // Since height is uint8_t

    total_src_size = (size_t)(height)* (size_t)(src_stride);
    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    if (!src_buffer) exit(1);
    src = src_buffer;

    // Initialize src with non-zero predictable pattern
    for (size_t i = 0; i < total_src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    // Dst: written in chunks of 4*dst_stride twice per loop iteration -> 8 rows total
    // Ensure dst can hold at least as many rows as processed
    dst_stride = 2048; // Reasonable smaller stride
    total_dst_size = (size_t)(height / 8) * 8 * (size_t)(dst_stride); // 8 output rows per 8 input rows
    if (total_dst_size == 0) total_dst_size = 8 * dst_stride;
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);
    if (!dst_buffer) exit(1);
    dst = dst_buffer;

    // Initialize dst
    for (size_t i = 0; i < total_dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    loop_cnt = height >> 3;
}