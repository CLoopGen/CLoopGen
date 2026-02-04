#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    png_uint_32 j;
    for (j = 0; j < row_width; j++) {
        png_byte pixel = *local_sp;
        png_byte result = (pixel & 255U) == gray ? 0 : 255;
        *local_dp-- = pixel;
        *local_dp-- = result;
        local_sp--;
    }
    sp = local_sp;
    dp = local_dp;
}
