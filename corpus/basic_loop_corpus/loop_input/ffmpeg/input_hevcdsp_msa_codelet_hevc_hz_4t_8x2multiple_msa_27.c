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
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Set dimensions: aim for ~64MB of source data to ensure measurable runtime
    height = 8192;
    src_stride = 8192;  // Width of 8192 bytes per row
    dst_stride = 8192;  // Corresponding dst stride in int16_t units

    total_src_size = (size_t)(2 * height) * src_stride;  // We access up to 2*height rows due to loop increment
    total_dst_size = (size_t)(2 * height) * dst_stride * sizeof(int16_t);  // Each dst element is int16_t

    // Allocate buffers with sufficient space
    src_buffer = (uint8_t*)aligned_alloc(64, total_src_size);
    dst_buffer = (int16_t*)aligned_alloc(64, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize pointers to start of buffers
    src = src_buffer;
    dst = dst_buffer;

    // Touch memory to ensure pages are mapped, initialize with predictable values
    for (size_t i = 0; i < total_src_size; i++) {
        src_buffer[i] = i & 0xFF;
    }
    for (size_t i = 0; i < total_dst_size / sizeof(int16_t); i++) {
        dst_buffer[i] = 0;
    }
}