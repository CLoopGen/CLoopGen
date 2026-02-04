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
    png_uint_32 temp1, temp2;
    for (i = 0, sp = dp = row; i < row_width; i++) {
        sp += 6;
        dp = sp;
        temp1 = 255 - *(sp + 1);
        temp2 = 255 - *(sp + 2);
        *(dp++) = (png_byte)temp1;
        *dp = (png_byte)temp2;
        sp += 2;
    }
}
