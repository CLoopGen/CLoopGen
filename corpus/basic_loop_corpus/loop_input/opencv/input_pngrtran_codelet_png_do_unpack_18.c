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
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of data

    sp_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 255);
    }

    row_width = data_size - 1;
    sp = &sp_buffer[data_size - 1];
    dp = &dp_buffer[data_size - 1];
    shift = 0;
}