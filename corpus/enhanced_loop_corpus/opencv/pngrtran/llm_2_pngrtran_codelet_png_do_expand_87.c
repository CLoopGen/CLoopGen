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
    // Variant 1: Consecutive memory access with offset indexing (eliminates repeated pointer decrementing)
    png_bytep sp_local = sp;
    png_bytep dp_local = dp;
    for (i = 0; i < row_width; i++) {
        png_byte current_red   = *(sp_local - 2);
        png_byte current_green = *(sp_local - 1);
        png_byte current_blue  = *(sp_local);

        if (current_red == red && current_green == green && current_blue == blue)
            *dp_local-- = 0;
        else
            *dp_local-- = 255;

        *dp_local-- = current_blue;
        *dp_local-- = current_green;
        *dp_local-- = current_red;

        sp_local -= 3; // Move input pointer by 3 bytes per pixel
    }
    sp = sp_local;
    dp = dp_local;
}
