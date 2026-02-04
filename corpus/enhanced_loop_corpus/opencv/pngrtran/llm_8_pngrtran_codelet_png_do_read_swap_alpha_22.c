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
    for (i = 0; i < row_width * 2; i += 2) {
        png_byte temp1, temp2;
        temp1 = *(--sp);
        temp2 = *(--sp);
        *(--dp) = temp1;
        *(--dp) = temp2;
    }
}
