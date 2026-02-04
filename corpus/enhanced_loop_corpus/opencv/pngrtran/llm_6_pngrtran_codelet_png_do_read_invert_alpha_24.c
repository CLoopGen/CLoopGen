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
    png_uint_32 j;
    for (j = 0; j < row_width; j++) {
        png_byte temp = (png_byte)(255 - sp[-4]);
        *(--dp) = temp;
        sp -= 4;
        dp -= 1;
    }
}
