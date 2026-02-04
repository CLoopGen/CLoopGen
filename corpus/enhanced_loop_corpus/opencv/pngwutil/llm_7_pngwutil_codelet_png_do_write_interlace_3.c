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
    png_uint_32 offset;
    int local_d = 0;
    int local_shift = 4;
    png_bytep local_dp = dp;
    for (i = png_pass_start[pass]; i < row_width; i += png_pass_inc[pass]) {
        offset = (size_t)(i >> 1);
        sp = row + offset;
        value = (*(sp) >> ((1 - (int)(i & 1)) << 2)) & 15;
        if (local_shift == 0) {
            *local_dp++ = (png_byte)local_d;
            local_d = value;
            local_shift = 4;
        } else {
            local_d |= (value << (local_shift - 4));
            local_shift -= 4;
        }
    }
    d = local_d;
    shift = local_shift;
    dp = local_dp;
}
