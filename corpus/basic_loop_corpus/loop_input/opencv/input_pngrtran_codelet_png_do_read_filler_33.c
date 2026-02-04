#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width = 65536;
png_byte lo_filler = 0xAB;
png_bytep sp;
png_bytep dp;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 262144; // ~256KB of input data

    sp_buffer = (png_byte*)malloc(data_size);
    dp_buffer = (png_byte*)malloc(data_size + 4 * (row_width));

    if (!sp_buffer || !dp_buffer) {
        free(sp_buffer);
        free(dp_buffer);
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    sp = sp_buffer + data_size;
    dp = dp_buffer + data_size + 4 * row_width;

    lo_filler = 0xAB;
}