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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime

    sp_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(data_size / 4 + 1, sizeof(png_byte)); // worst-case output size

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
    }

    sp = sp_buffer;
    dp = dp_buffer;
    shift = 6;
    v = 0;
    row_width = data_size;
}