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
    for (i = 0, rp = row; i < row_width; i++, rp += bytes_per_pixel) {
        png_byte temp1 = (png_byte)((256 + *rp + *(rp + 1)) & 255);
        png_byte temp2 = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
        *(rp) = temp1;
        *(rp + 2) = temp2;
    }
}
