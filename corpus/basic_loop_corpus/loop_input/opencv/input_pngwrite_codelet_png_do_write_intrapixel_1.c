#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep row = NULL;
int bytes_per_pixel;
png_uint_32 row_width;
png_bytep rp;
png_uint_32 i;

void init_vars() {
    bytes_per_pixel = 3;
    row_width = 16000000;

    row = (png_bytep)aligned_alloc(32, (size_t)row_width * bytes_per_pixel);
    if (!row) {
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < row_width * bytes_per_pixel; idx++) {
        row[idx] = (png_byte)(idx % 256);
    }
}

extern void loop(void);