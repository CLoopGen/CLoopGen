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
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    row_width = data_size / 5; // Each iteration consumes 4 bytes and produces 5-byte pattern

    // Adjust so that sp+4 stays in bounds: i < row_width implies 4*i + 4 <= data_size
    while (4 * row_width + 4 > data_size) {
        row_width--;
    }

    row = (png_bytep)aligned_alloc(32, data_size);
    if (!row) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        row[idx] = (png_byte)(idx % 251);
    }

    sp = NULL;
    dp = NULL;
    i = 0;
}