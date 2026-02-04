#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_uint_32 row_width;
png_bytep row;
png_bytep rp;
png_uint_32 i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    row = (png_bytep)aligned_alloc(32, data_size);
    if (!row) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        row[idx] = (png_byte)(idx % 256);
    }

    row_width = (data_size - 8) / 8; // ensures rp + 5 is always in bounds when i < row_width
}