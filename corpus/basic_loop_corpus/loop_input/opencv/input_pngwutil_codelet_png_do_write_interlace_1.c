#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_byte png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
png_byte png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};

png_uint_32 row_width = (1 << 20); // Approximately 1MB of pixel data (each bit-indexed)

static png_byte *row_data;
png_bytep row;
png_bytep sp;
png_bytep dp;
unsigned int shift;
int d;
int value;
png_uint_32 i;
int pass;

void init_vars() {
    pass = 0;
    shift = 7;
    d = 0;
    value = 0;
    i = 0;

    row_data = (png_byte*)calloc((row_width >> 3) + 2, sizeof(png_byte));
    if (!row_data) exit(1);
    row = row_data;

    dp = (png_bytep)calloc((row_width >> 3) + 2, sizeof(png_byte));
    if (!dp) exit(1);

    sp = row;
}