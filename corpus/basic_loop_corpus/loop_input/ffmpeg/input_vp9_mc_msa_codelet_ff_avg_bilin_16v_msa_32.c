#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Aim for ~64MB of data to target ~0.01s runtime on modern CPUs
    const int target_height = 16384;  // 16K rows
    const int width = 1024;           // 1KB per row
    height = target_height;

    src_stride = width;
    dst_stride = width;

    total_src_size = height * (size_t)src_stride;
    total_dst_size = height * (size_t)dst_stride;

    // Allocate buffers with padding to prevent under/overflow
    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data to non-zero
    for (size_t i = 0; i < total_src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    memset(dst_buffer, 0, total_dst_size);

    // Assign pointers
    src = src_buffer;
    dst = dst_buffer;
}

// Cleanup function to avoid memory leaks (not called by loop but good practice)
void cleanup_vars() {
    free(src_buffer);
    free(dst_buffer);
}