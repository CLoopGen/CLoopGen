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
    row_width = 64 * 1024 * 1024; // 64 million elements, ~64MB input

    row = (png_bytep)aligned_alloc(32, row_width * 2 * sizeof(png_byte));
    if (!row) {
        exit(1);
    }

    for (size_t idx = 0; idx < row_width * 2; ++idx) {
        row[idx] = (png_byte)(idx % 256);
    }

    sp = NULL;
    dp = NULL;
    i = 0;
}