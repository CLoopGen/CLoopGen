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
    for (i = 0; i < row_width; i++) {
        png_byte s_current = *sp;
        png_byte s_prev = *(sp - 1);
        *(dp - 0) = s_prev;
        *(dp - 1) = s_current;
        *(dp - 2) = s_prev;
        *(dp - 3) = s_current;
        *(dp - 4) = s_prev;
        *(dp - 5) = s_current;
        *(dp - 6) = s_prev;
        *(dp - 7) = s_current;
        dp -= 8;
        sp -= 2;
    }
}
