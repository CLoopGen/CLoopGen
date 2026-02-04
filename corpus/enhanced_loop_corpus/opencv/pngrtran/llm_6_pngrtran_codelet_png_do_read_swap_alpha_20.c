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
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_byte temp1, temp2, temp3, temp4;
    for (i = 0; i < row_width; i++) {
        temp1 = *(--sp);
        temp2 = *(--sp);
        temp3 = *(--sp);
        temp4 = *(--sp);
        *(--dp) = temp4;
        *(--dp) = temp3;
        *(--dp) = temp2;
        *(--dp) = temp1;
    }
}
