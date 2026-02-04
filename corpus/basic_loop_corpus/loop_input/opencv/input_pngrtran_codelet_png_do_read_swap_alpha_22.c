#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 row_width = 16777216; // ~16.7M elements to target ~0.01s runtime

static png_byte *sp_buffer;
static png_byte *dp_buffer;

png_bytep sp;
png_bytep dp;
png_byte save;
png_uint_32 i;

void init_vars() {
    sp_buffer = (png_byte*)malloc(row_width * 2 * sizeof(png_byte));
    dp_buffer = (png_byte*)malloc(row_width * 2 * sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < row_width * 2; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
        dp_buffer[idx] = 0;
    }

    sp = sp_buffer + row_width * 2;
    dp = dp_buffer + row_width * 2;
}