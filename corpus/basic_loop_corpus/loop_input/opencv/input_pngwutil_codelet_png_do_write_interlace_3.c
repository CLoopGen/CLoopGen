#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_byte png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
png_byte png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};

png_uint_32 row_width = 1 << 20; // ~1M elements, sufficient for ~0.01s runtime
png_bytep row;
png_bytep sp;
png_bytep dp;
unsigned int shift;
int pass = 0;
int d = 0;
int value;
png_uint_32 i;

void init_vars() {
    row = (png_bytep)aligned_alloc(16, sizeof(png_byte) * ((row_width >> 1) + 1));
    dp = (png_bytep)aligned_alloc(16, sizeof(png_byte) * ((row_width >> 1) + 1));

    if (!row || !dp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < ((row_width >> 1) + 1); ++idx) {
        row[idx] = (png_byte)(idx & 255);
        dp[idx] = 0;
    }

    pass = 0;
    shift = 4;
    d = 0;
}