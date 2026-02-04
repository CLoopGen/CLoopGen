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
extern png_uint_32 shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_shift = shift;
    for (i = 0; i < row_width; i++) {
        png_byte val = *(sp - (temp_shift >= 7 ? (i / 8) : 0));
        *dp = (png_byte)((val >> temp_shift) & 1);
        if (temp_shift == 7) {
            temp_shift = 0;
        } else {
            temp_shift++;
        }
        dp--;
    }
    shift = temp_shift;
}
