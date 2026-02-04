#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_byte png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
png_byte png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};

png_uint_32 row_width = 1 << 20; // Approximately 1MB of data (adjustable for timing)

png_bytep row;
png_bytep dp;
int pass;
png_bytep sp;
unsigned int shift;
int d;
int value;
png_uint_32 i;

void init_vars() {
    row = (png_bytep)malloc(row_width * sizeof(png_byte));
    dp = (png_bytep)malloc((row_width + 3) / 4 * sizeof(png_byte)); // conservative allocation
    if (!row || !dp) {
        exit(1);
    }

    for (i = 0; i < row_width; ++i) {
        row[i] = (png_byte)(i & 0xFF);
    }

    pass = 0;
    shift = 6;
    d = 0;
    sp = NULL;
    value = 0;
}