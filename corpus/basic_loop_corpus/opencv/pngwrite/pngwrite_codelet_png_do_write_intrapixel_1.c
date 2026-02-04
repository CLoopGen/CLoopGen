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
for (i = 0 , rp = row; i < row_width; i++ , rp += bytes_per_pixel) {
    *(rp) = (png_byte)(*rp - *(rp + 1));
    *(rp + 2) = (png_byte)(*(rp + 2) - *(rp + 1));
}

}
