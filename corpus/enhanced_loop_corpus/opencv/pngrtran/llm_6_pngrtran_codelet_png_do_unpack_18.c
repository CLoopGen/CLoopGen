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
    png_bytep temp_sp = sp;
    png_bytep temp_dp = dp;
    for (i = 0; i < row_width; i++) {
        png_byte val = *(temp_sp - (temp_shift == 4 ? 1 : 0));
        *temp_dp = (png_byte)((val >> temp_shift) & 15);
        temp_shift = (temp_shift == 4) ? 0 : 4;
        temp_sp -= (temp_shift == 0) ? 1 : 0;
        temp_dp--;
    }
    shift = temp_shift;
    sp = temp_sp;
    dp = temp_dp;
}
