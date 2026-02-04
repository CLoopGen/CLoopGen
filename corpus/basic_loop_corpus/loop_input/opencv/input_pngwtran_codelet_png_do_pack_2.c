#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep sp;
png_bytep dp;
unsigned int shift;
int v;
png_uint_32 i;
png_uint_32 row_width;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    row_width = 67108864; // 64M elements to target ~0.01 sec on modern CPU

    sp_buffer = (png_byte*)aligned_alloc(32, sizeof(png_byte) * row_width);
    dp_buffer = (png_byte*)aligned_alloc(32, sizeof(png_byte) * ((row_width + 1) / 2));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < row_width; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 255);
    }

    sp = sp_buffer;
    dp = dp_buffer;
    shift = 4;
    v = 0;
}