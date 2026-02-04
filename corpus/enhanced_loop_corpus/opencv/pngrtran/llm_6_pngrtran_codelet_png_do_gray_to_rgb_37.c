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
    png_uint_32 temp1, temp2;
    for (i = 0; i < row_width; i++) {
        temp1 = *(sp - 1);
        temp2 = *sp;
        *(dp - 5) = temp2;
        *(dp - 4) = temp1;
        *(dp - 3) = temp2;
        *(dp - 2) = temp1;
        *(dp - 1) = temp2;
        *dp = temp2;
        dp -= 6;
        sp--;
    }
}
