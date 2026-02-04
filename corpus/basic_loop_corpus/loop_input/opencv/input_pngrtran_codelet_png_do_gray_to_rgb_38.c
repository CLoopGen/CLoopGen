#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width = 64 * 1024 * 1024; // ~64 million iterations to target ~0.01s runtime
png_bytep sp;
png_bytep dp;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t total_size = row_width + 8; // Add padding for safe pre-decrement and access

    sp_buffer = (png_byte*)aligned_alloc(32, total_size);
    dp_buffer = (png_byte*)aligned_alloc(32, total_size);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < total_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    // Set sp to point near the end so that --sp operations stay in bounds
    // We need at least 4 decrements per loop, over row_width iterations -> need ~4*row_width headroom
    // But our loop does: dp-- four times, sp-- three times per iteration
    // So we need at least 3 * row_width usable space before initial sp
    // Allocate sufficient buffer and set starting pointers appropriately

    // Recompute with proper safety margin
    const size_t margin = 4 * row_width;
    const size_t extended_size = margin + row_width;

    free(sp_buffer);
    free(dp_buffer);

    sp_buffer = (png_byte*)aligned_alloc(32, extended_size);
    dp_buffer = (png_byte*)aligned_alloc(32, extended_size);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < extended_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
        dp_buffer[idx] = 0;
    }

    // Set sp to end of valid data segment, dp to end of destination buffer
    sp = sp_buffer + margin + row_width - 1;
    dp = dp_buffer + margin + row_width - 1;
}