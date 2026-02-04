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

#define DATA_SIZE (128U * 1024 * 1024)

static png_byte data_buffer[DATA_SIZE];

void init_vars() {
    row_width = (DATA_SIZE - 8) / 6;  
    row = data_buffer;
    sp = NULL;
    dp = NULL;
    i = 0;
}