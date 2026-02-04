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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width * 2; i += 2) {
        *(dp - 0) = *(sp - 1);
        *(dp - 1) = *(sp - 0);
        *(dp - 2) = *(sp - 1);
        *(dp - 3) = *(sp - 0);
        dp -= 4;
        sp -= 2;
    }
}
