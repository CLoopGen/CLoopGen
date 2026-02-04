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
    for (i = 0; i < row_width; i++) {
        png_bytep rp = row + i * bytes_per_pixel;
        png_uint_32 s0 = (png_uint_32)(*(rp) << 8) | *(rp + 1);
        png_uint_32 s1 = (png_uint_32)(*(rp + 2) << 8) | *(rp + 3);
        png_uint_32 s2 = (png_uint_32)(*(rp + 4) << 8) | *(rp + 5);
        png_uint_32 red = (s0 + s1 + 65536) & 65535;
        png_uint_32 blue = (s2 + s1 + 65536) & 65535;
        *(rp) = (png_byte)((red >> 8) & 255);
        *(rp + 1) = (png_byte)(red & 255);
        *(rp + 4) = (png_byte)((blue >> 8) & 255);
        *(rp + 5) = (png_byte)(blue & 255);
    }
}
