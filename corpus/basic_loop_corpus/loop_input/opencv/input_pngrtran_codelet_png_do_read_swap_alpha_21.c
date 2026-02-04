#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 row_width;
png_bytep sp;
png_bytep dp;
png_byte save[2];
png_uint_32 i;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB to target ~0.01 sec runtime on modern CPU

    row_width = data_size / 8;

    sp_buffer = (png_byte*)aligned_alloc(32, data_size + 16);
    dp_buffer = (png_byte*)aligned_alloc(32, data_size + 16);

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    sp = sp_buffer + data_size;
    dp = dp_buffer + data_size;

    for (size_t j = 0; j < data_size; ++j) {
        sp_buffer[j] = (png_byte)(j & 0xFF);
    }

    save[0] = 0;
    save[1] = 0;
}