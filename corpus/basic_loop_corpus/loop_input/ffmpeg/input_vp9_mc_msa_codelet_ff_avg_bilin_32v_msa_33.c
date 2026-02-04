#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;

void init_vars() {
    total_size = 64 * 1024 * 1024; // 64 MB for substantial memory footprint

    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src_stride = 8192; // Large stride to avoid cache line conflicts
    dst_stride = 8192;
    height = 8192; // Ensures loop runs for (8192 >> 2) = 2048 iterations

    src = src_buffer;
    dst = dst_buffer;
}