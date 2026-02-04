#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width;
png_byte lo_filler;
png_bytep sp;
png_bytep dp;

static png_byte *sp_buffer;
static png_byte *dp_buffer;
static size_t buffer_size;

void init_vars() {
    // Set row_width to control data size: aim for ~100MB of operations to take ~0.01s
    row_width = 25000000;  // 25M iterations, each processing 2 bytes -> 50MB total filler/data
    buffer_size = row_width + 8;  // Add padding to prevent underflow on pointer decrements

    // Allocate buffers with sufficient size
    sp_buffer = (png_byte*)calloc(buffer_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(buffer_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    // Initialize source data
    for (png_uint_32 j = 0; j < row_width; j++) {
        sp_buffer[j] = (png_byte)(j & 0xFF);
    }

    // Set pointers to end of valid data (to allow pre-decrement in loop)
    sp = sp_buffer + row_width - 1;
    dp = dp_buffer + row_width * 2;  // Reserve space for inserted fillers

    // Set filler byte
    lo_filler = 0xFF;
}