#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern  png_byte png_pass_start[7];
extern  png_byte png_pass_inc[7];
extern png_bytep row;
extern int pass;
extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int d;
extern int value;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 j;
    png_bytep temp_dp = dp;
    int temp_d = d;
    int temp_shift = shift;
    for (i = png_pass_start[pass]; i < row_width; i += png_pass_inc[pass]) {
        sp = row + (size_t)(i >> 1);
        value = (*sp >> ((1 - (int)(i & 1)) << 2)) & 15;
        temp_d |= (value << temp_shift);
        if (temp_shift == 0) {
            temp_shift = 4;
            *temp_dp++ = (png_byte)temp_d;
            temp_d = 0;
        } else
            temp_shift -= 4;
    }
    d = temp_d;
    shift = temp_shift;
    dp = temp_dp;
}
