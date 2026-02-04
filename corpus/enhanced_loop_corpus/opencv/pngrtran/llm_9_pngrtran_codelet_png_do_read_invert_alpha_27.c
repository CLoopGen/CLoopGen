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
    for (i = 0; i < row_width / 2; i++) {
        png_byte val1 = *(--sp);
        png_byte val2 = *(--sp);
        *(--dp) = (png_byte)(255 - val1);
        *(--dp) = (png_byte)(255 - val2);
        *(--dp) = (png_byte)(255 - val1);
        *(--dp) = (png_byte)(255 - val2);
        sp -= 2;
        dp -= 2;
    }
}
