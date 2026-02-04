#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;
unsigned int gray_high;
unsigned int gray_low;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    // Set parameters
    row_width = 65536;  // Controls number of loop iterations
    gray_high = 255;
    gray_low = 0;

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // Each iteration reads from sp and writes to dp, decrements both by 4 bytes
    // Also accesses (sp - 1), so we need extra headroom at the beginning
    // Total sp read offset: from sp_start down to sp_start - 2*row_width - 1
    // Total dp write offset: dp_start down to dp_start - 4*row_width

    size_t sp_size = 2 * row_width + 16;  // Extra padding at front and back
    size_t dp_size = 8 * row_width + 16;

    sp_buffer = (png_byte*)calloc(sp_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(dp_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    // Initialize sp to point near the end of sp_buffer so that (sp - 1) is valid
    // and we can decrement it row_width times safely
    sp = sp_buffer + sp_size - 1;
    dp = dp_buffer + dp_size - 1;

    // Initialize data in sp_buffer for testing conditions
    // Fill most of the buffer with alternating pattern
    for (png_uint_32 idx = 0; idx < 2 * row_width; idx++) {
        sp_buffer[sp_size - 1 - idx] = (idx % 2) ? gray_low : gray_high;
    }
    // Ensure (sp - 1) access is safe even when sp points to first meaningful element
    sp_buffer[sp_size - 1 - 2 * row_width] = gray_high;
}