#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width = 64000000;
png_byte lo_filler = 0xAB;
png_byte *sp_base;
png_byte *dp_base;
png_bytep sp;
png_bytep dp;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024;

    sp_base = (png_bytep)aligned_alloc(32, data_size);
    dp_base = (png_bytep)aligned_alloc(32, data_size);

    if (!sp_base || !dp_base) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        sp_base[i] = (png_byte)(i & 0xFF);
        dp_base[i] = 0x00;
    }

    sp = sp_base + data_size - 1;
    dp = dp_base + data_size - 1;

    i = 0;
}