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

// Allocate sufficient space: sp and dp will be decremented, so we place data at the end
static png_byte *sp_buffer;
static png_byte *dp_buffer;

png_bytep sp;
png_bytep dp;

void init_vars() {
    const size_t total_size = row_width * 8; // Each iteration processes 8 bytes

    sp_buffer = (png_byte*)calloc(total_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(total_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < total_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx % 251); // Prime pattern to avoid zero-only
    }

    // Set pointers to end of buffers for decrementing access
    sp = sp_buffer + total_size;
    dp = dp_buffer + total_size;
}