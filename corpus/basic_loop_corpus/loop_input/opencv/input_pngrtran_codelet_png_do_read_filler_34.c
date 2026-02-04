#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width = 16000000; // ~16M iterations to target ~0.01s runtime
png_byte hi_filler = 0xFF;
png_byte lo_filler = 0x00;

// Allocate sufficient space: each iteration reads 6 bytes from sp and writes 8 bytes to dp
// We run (row_width - 1) iterations, so we need up to 6*(row_width-1) from sp and 8*(row_width-1) to dp
// Add padding at the end since pointers are decremented before access

static png_byte *sp_buffer;
static png_byte *dp_buffer;

png_bytep sp;
png_bytep dp;

void init_vars() {
    const png_uint_32 num_iterations = row_width - 1;
    const png_uint_32 sp_size = 6 * num_iterations + 8; // extra padding for safety
    const png_uint_32 dp_size = 8 * num_iterations + 8;

    sp_buffer = (png_byte*)calloc(sp_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(dp_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize sp_buffer with non-trivial data
    for (png_uint_32 idx = 0; idx < sp_size; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    // Set sp to point just past valid data so --sp starts at last byte
    sp = sp_buffer + sp_size;
    dp = dp_buffer + dp_size;
}