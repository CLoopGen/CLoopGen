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
    for (i = 0, sp = dp = row; i < row_width; i++) {
        png_byte temp1 = *(sp);
        png_byte temp2 = *(sp + 1);
        *(dp) = temp2;
        *(dp + 1) = temp1;
        sp += 2;
        dp += 2;
    }
}
