#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t input_size = 128 * 1024 * 1024; // ~128MB input data
    const int tile_width = 2;
    const int tile_height = 2;
    const int src_pitch = ((tile_width * 2) + 7) & ~7; // Align to 8-byte boundary
    const int dst_pitch = tile_height * 3;

    src_stride = src_pitch;
    dst_stride = dst_pitch;
    width = (input_size / 2) / src_stride; // Ensure we have enough data for width-4 safe access

    // Clamp width to ensure i < width - 2 is valid and loop runs sufficiently
    if (width > 10000) width = 10000;

    // Allocate buffers with padding to prevent out-of-bounds access
    // We access src rows from -1 to +2 and columns from -2 to +2 relative to center
    const int padded_src_rows = tile_height + 4; // Add 2 before and 2 after
    const int padded_src_cols = tile_width * 2 + 4; // Add 2 elements before and after in horizontal direction
    const int total_src_size = padded_src_rows * src_stride;

    const int total_dst_size = width * dst_stride * 2; // Estimate output size

    src_buffer = aligned_alloc(8, total_src_size);
    dst_buffer = aligned_alloc(8, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source buffer with non-zero data to avoid division-by-zero or trivial optimizations
    for (size_t idx = 0; idx < total_src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 251);
    }

    // Initialize destination buffer
    for (size_t idx = 0; idx < total_dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    // Set src to point at the first "valid" position (after one row/column padding)
    src = src_buffer + (1 * src_stride + 2 * 1); // Leave room for [-1] row and [-1] column (in 2x scaled units)
    dst = dst_buffer;
}

// Initialize external variables using a constructor function
__attribute__((constructor))
static void initialize() {
    init_vars();
}