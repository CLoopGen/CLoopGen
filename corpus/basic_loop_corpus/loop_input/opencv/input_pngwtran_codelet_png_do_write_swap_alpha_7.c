#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep row;
png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB to target ~0.01 sec runtime

    row = (png_bytep)aligned_alloc(64, data_size);
    if (!row) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        row[idx] = (png_byte)(idx % 251);
    }

    row_width = (data_size - 20) / 10;
    row_width = (row_width > 0) ? row_width : 0;
}

void loop();