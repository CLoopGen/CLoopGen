#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red;
extern png_byte green;
extern png_byte blue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_byte local_red, local_green, local_blue;
    local_red = red;
    local_green = green;
    local_blue = blue;

    for (i = 0; i < row_width; i++) {
        png_byte s0 = *(sp - 0);
        png_byte s1 = *(sp - 1);
        png_byte s2 = *(sp - 2);

        int match = (s2 == local_red && s1 == local_green && s0 == local_blue) ? 0 : 255;

        *(dp - 0) = match;
        *(dp - 1) = s0;
        *(dp - 2) = s1;
        *(dp - 3) = s2;

        sp -= 3;
        dp -= 4;
    }
}
