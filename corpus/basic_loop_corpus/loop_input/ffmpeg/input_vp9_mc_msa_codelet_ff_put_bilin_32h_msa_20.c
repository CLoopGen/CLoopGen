#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
    // Aim for approximately 64MB of source data to ensure loop runs about 0.01s
    size_t target_data_size = 64 * 1024 * 1024; // 64 MB
    height = (target_data_size / 256); // Assume average row stride around 256
    if (height < 4) height = 4;
    height &= ~1; // Ensure even height since we do height >> 1

    src_stride = 256; // Simulate stride with padding
    dst_stride = 256;

    total_src_size = height * src_stride;
    total_dst_size = height * dst_stride;

    // Allocate buffers with proper alignment
    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (avoid undefined behavior)
    memset(src_buffer, 0x5A, total_src_size);
    memset(dst_buffer, 0, total_dst_size);

    // Initialize external pointers
    src = src_buffer;
    dst = dst_buffer;

    // Initialize loop counter (will be overwritten in loop, but set safely)
    loop_cnt = 0;
}

// Cleanup function to avoid memory leaks (not called here, but good practice)
void cleanup_vars() {
    free(src_buffer);
    free(dst_buffer);
}