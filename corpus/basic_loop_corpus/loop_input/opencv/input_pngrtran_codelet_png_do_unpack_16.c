#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width;
png_bytep sp;
png_bytep dp;
png_uint_32 shift;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data for sufficient runtime (~0.01 sec on modern CPU)

    row_width = data_size;
    shift = 0;

    sp_buffer = (png_byte*)aligned_alloc(64, data_size * sizeof(png_byte));
    dp_buffer = (png_byte*)aligned_alloc(64, data_size * sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
        dp_buffer[idx] = 0;
    }

    sp = &sp_buffer[data_size - 1];
    dp = &dp_buffer[data_size - 1];
}