#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB for significant runtime (~0.01s on modern CPU)

    // Allocate large buffers to ensure meaningful execution time
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffer contents
    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    // Set parameters to ensure no out-of-bounds access
    src_stride = 1024;  // stride of 1KB
    dst_stride = 1024;
    height = (total_data_size / 2) / src_stride;  // ensures two src updates per iteration

    // Ensure that (height >> 1) * 2 * src_stride <= total_data_size
    // Trim height if needed to fit buffer
    while (height > 0 && (int64_t)height * 2 * src_stride > (int64_t)total_data_size) {
        height--;
    }

    src = src_buffer;
    dst = dst_buffer;
}

// Definitions must be present for linkage
uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;