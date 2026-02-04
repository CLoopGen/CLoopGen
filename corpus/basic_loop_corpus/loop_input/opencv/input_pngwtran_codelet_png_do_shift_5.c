#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;
typedef unsigned short png_uint_16;

png_bytep row = NULL;
int shift_start[4];
int shift_dec[4];
unsigned int channels;
png_bytep bp;
png_uint_32 i;
png_uint_32 istop;

void init_vars() {
    channels = 4;
    istop = 16777216; // ~16.7M iterations, roughly 0.01s on modern CPUs

    for (int c = 0; c < 4; c++) {
        shift_start[c] = 24 - c * 8;
        shift_dec[c] = 8;
    }

    size_t row_size = istop * 2 * sizeof(png_byte); // Each iteration reads 2 bytes, writes 2 bytes
    row = (png_bytep)aligned_alloc(16, row_size);
    if (!row) exit(1);

    bp = row;

    for (size_t idx = 0; idx < row_size; idx++) {
        row[idx] = (png_byte)(idx & 255);
    }
}