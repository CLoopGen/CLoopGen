#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_uint_32 row_width = 8000000; // ~24MB of data (8e6 * 3 bytes)
png_bytep row;
png_bytep rp;
png_uint_32 i;

void init_vars() {
    row = (png_bytep)aligned_alloc(32, row_width * 3);
    if (!row) {
        exit(1);
    }
    for (png_uint_32 idx = 0; idx < row_width * 3; ++idx) {
        row[idx] = (png_byte)(idx % 256);
    }
}