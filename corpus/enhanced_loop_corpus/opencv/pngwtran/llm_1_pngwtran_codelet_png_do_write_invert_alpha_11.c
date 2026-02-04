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
    for (i = 0; i < row_width; i++) {
        sp = dp = row + i * 6;
        sp += 6;
        dp = sp;
        for (int j = 0; j < 2; j++) {
            *(dp++) = (png_byte)(255 - *(sp++));
        }
    }
}
