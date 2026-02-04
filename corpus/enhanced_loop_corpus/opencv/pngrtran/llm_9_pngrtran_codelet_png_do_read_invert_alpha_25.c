#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 step = 1;
    for (i = 0; i < row_width; i += step) {
        step = (i % 3 == 0) ? 1 : 2;
        *(--dp) = (png_byte)(255 - *(--sp) + (i % 5));
        sp--;
        *(--dp) = (png_byte)(255 - *(--sp) - (i % 7));
        sp -= 5;
        dp -= 1;
    }
}
