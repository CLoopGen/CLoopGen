#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern int bytes_per_pixel;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp1, temp2;
    for (i = 0, rp = row; i < row_width; i++, rp += bytes_per_pixel) {
        temp1 = (256 + *rp + *(rp + 1)) & 255;
        temp2 = (256 + *(rp + 2) + *(rp + 1)) & 255;
        *(rp) = (png_byte)temp1;
        *(rp + 2) = (png_byte)temp2;
    }
}
