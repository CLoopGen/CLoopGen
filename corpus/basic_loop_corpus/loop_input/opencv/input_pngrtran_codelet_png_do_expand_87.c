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
png_byte red;
png_byte green;
png_byte blue;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    red = 255;
    green = 128;
    blue = 64;

    row_width = 64 * 1024; 

    size_t sp_size = (row_width * 3) + 2;
    sp_buffer = (png_byte*)calloc(sp_size, sizeof(png_byte));
    if (!sp_buffer) exit(1);

    for (size_t idx = 0; idx < sp_size; idx++) {
        sp_buffer[idx] = rand() % 256;
    }

    size_t dp_size = row_width * 4 * 3; 
    dp_buffer = (png_byte*)calloc(dp_size, sizeof(png_byte));
    if (!dp_buffer) exit(1);

    sp = sp_buffer + sp_size - 1;
    dp = dp_buffer + dp_size - 1;
}