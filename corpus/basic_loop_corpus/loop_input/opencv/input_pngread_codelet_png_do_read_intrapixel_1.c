#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_uint_32 row_width = 100000; // ~100k pixels, total data size ~600KB assuming 6 bytes per pixel
int bytes_per_pixel = 6;
png_bytep row = NULL;
png_bytep rp = NULL;
png_uint_32 i = 0;

void init_vars() {
    row = (png_bytep)aligned_alloc(32, (size_t)row_width * bytes_per_pixel);
    if (!row) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < row_width * bytes_per_pixel; idx++) {
        row[idx] = (png_byte)(idx % 256);
    }
}