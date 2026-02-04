#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 row_width = 64 * 1024 * 1024; // ~256MB of data processed
png_bytep sp;
png_bytep dp;
png_byte save[2];
png_uint_32 i;

void init_vars() {
    size_t total_size = row_width * 4; // Each iteration processes 4 bytes from sp and writes 4 to dp

    png_bytep sp_buffer = (png_bytep)aligned_alloc(32, total_size);
    png_bytep dp_buffer = (png_bytep)aligned_alloc(32, total_size);

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
        dp_buffer[idx] = 0;
    }

    sp = sp_buffer + total_size;
    dp = dp_buffer + total_size;

    save[0] = 0;
    save[1] = 0;
}