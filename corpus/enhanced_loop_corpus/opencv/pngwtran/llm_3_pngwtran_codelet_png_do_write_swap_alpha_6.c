#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , sp = dp = row; i < row_width; i++) {
    png_uint_32 offset = i * 5;
    png_byte save = row[offset + 0];
    row[offset + 0] = row[offset + 1];
    row[offset + 1] = row[offset + 2];
    row[offset + 2] = row[offset + 3];
    row[offset + 3] = row[offset + 4];
    row[offset + 4] = save;
}
}
