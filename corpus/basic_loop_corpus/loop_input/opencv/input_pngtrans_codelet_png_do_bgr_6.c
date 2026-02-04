#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep row = NULL;
png_uint_32 row_width;
png_bytep rp;
png_uint_32 i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    row_width = data_size / 4; // since each iteration steps by 4 bytes

    row = (png_bytep)aligned_alloc(16, data_size);
    if (!row) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        row[idx] = (png_byte)(idx % 251);
    }

    rp = NULL;
    i = 0;
}