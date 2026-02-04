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

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;

void init_vars() {
    // Allocate approximately 64MB of source and destination data to achieve ~0.01s runtime
    size_t total_data_size = (1 << 26); // 64 MB

    // Use a block height of around 4096 for realistic striding behavior
    height = 4096;

    // Calculate width per row: total_data_size / height, but ensure it's reasonable
    int width = (total_data_size + height - 1) / height;

    // Ensure width is at least 16 bytes to avoid degenerate cases
    if (width < 16) width = 16;

    // Adjust height so that 4-row chunks align well
    height = (height + 3) & ~3; // Round up to multiple of 4

    // Stride in bytes: allow some padding to simulate real image/video processing
    src_stride = (width + 15) & ~15; // 16-byte aligned stride
    dst_stride = (width + 15) & ~15;

    size_t src_buffer_size = (size_t)height * (size_t)src_stride;
    size_t dst_buffer_size = (size_t)height * (size_t)dst_stride;

    // Allocate buffers with proper alignment
    internal_src_buffer = aligned_alloc(32, src_buffer_size);
    internal_dst_buffer = aligned_alloc(32, dst_buffer_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or predictable pattern)
    memset(internal_src_buffer, 0x5A, src_buffer_size);
    memset(internal_dst_buffer, 0, dst_buffer_size);

    // Assign external pointers
    src = internal_src_buffer;
    dst = internal_dst_buffer;

    // Ensure loop_cnt will be positive: height >> 2
    loop_cnt = height >> 2;
}

// Cleanup function to free allocated memory (not required by spec, but good practice)
void cleanup_vars() {
    free(internal_src_buffer);
    free(internal_dst_buffer);
}