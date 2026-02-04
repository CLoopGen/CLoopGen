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
extern unsigned int gray_high;
extern unsigned int gray_low;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing (unrolled-like pattern)
    png_bytep sp_local = sp;
    png_bytep dp_local = dp;
    png_uint_32 i_local = 0;

    for (i_local = 0; i_local < row_width; i_local++) {
        png_byte prev_val = *(sp_local - 1);
        png_byte curr_val = *(sp_local);

        if ((prev_val & 255U) == gray_high && (curr_val & 255U) == gray_low) {
            *dp_local-- = 0;
            *dp_local-- = 0;
        } else {
            *dp_local-- = 255;
            *dp_local-- = 255;
        }
        *dp_local-- = *sp_local--;
        *dp_local-- = *sp_local--;
    }

    sp = sp_local;
    dp = dp_local;
}
