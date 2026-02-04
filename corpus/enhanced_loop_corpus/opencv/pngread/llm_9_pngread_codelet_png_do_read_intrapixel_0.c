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
    for (i = 0, rp = row; i < row_width * 2; i += 2, rp += bytes_per_pixel * 2) {
        if (i + 1 < row_width) {
            *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
            *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
            png_bytep next_rp = rp + bytes_per_pixel;
            *(next_rp) = (png_byte)((256 + *next_rp + *(next_rp + 1)) & 255);
            *(next_rp + 2) = (png_byte)((256 + *(next_rp + 2) + *(next_rp + 1)) & 255);
        }
    }
}
