#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_byte green_high;
extern png_byte blue_high;
extern png_byte red_low;
extern png_byte green_low;
extern png_byte blue_low;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red_high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width; i++) {
        png_byte s0 = *(sp - 5), s1 = *(sp - 4), s2 = *(sp - 3);
        png_byte s3 = *(sp - 2), s4 = *(sp - 1), s5 = *(sp);

        int diff_r = (s0 ^ red_high) | (s1 ^ red_low);
        int diff_g = (s2 ^ green_high) | (s3 ^ green_low);
        int diff_b = (s4 ^ blue_high) | (s5 ^ blue_low);
        int is_match = !(diff_r | diff_g | diff_b);

        *dp-- = is_match ? 0 : 255;
        *dp-- = is_match ? 0 : 255;

        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
    }
}
