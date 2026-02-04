#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_shift = shift;
    for (i = 0; i < row_width; i++) {
        png_byte val = *(sp - (temp_shift / 8)); // Introduce base pointer offset dependency
        if ((val >> (temp_shift & 7)) & 1)
            *dp = 255;
        else
            *dp = 0;
        dp--;
        temp_shift++;
        if ((temp_shift & 7) == 0) {
            sp--;
        }
    }
    shift = temp_shift & 7; // Update shift in post-loop assignment (WAW removed from loop body)
}
