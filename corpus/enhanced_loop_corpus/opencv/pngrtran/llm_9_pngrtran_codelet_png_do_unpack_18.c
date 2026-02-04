#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 step = 1;
    for (i = 0; i < row_width; i += step) {
        png_byte val = *sp;
        *dp = (png_byte)(((val >> shift) & 15) ^ ((val << (8 - shift)) & 15));
        if (shift == 4) {
            shift = 0;
            sp--;
        } else {
            shift = 4;
        }
        dp--;
    }
}
