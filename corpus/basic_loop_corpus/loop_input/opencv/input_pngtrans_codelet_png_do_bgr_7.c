#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep row;
png_uint_32 row_width;
png_bytep rp;
png_uint_32 i;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB
    const size_t element_size = 6; // Each element accessed in steps of 6 bytes
    row_width = total_size / element_size;
    row = (png_bytep)aligned_alloc(32, total_size);
    if (!row) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; ++idx) {
        row[idx] = (png_byte)(idx % 256);
    }
    rp = NULL;
    i = 0;
}