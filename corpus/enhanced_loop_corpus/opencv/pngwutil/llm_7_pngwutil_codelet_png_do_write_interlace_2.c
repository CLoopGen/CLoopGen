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
    png_uint_32 local_i = png_pass_start[pass];
    int local_shift = shift;
    int local_d = d;
    png_bytep local_dp = dp;
    png_bytep local_sp;
    int local_value;

    while (local_i < row_width) {
        local_sp = row + (size_t)(local_i >> 2);
        local_value = (*local_sp >> ((3 - (int)(local_i & 3)) << 1)) & 3;
        local_d |= (local_value << local_shift);

        if (local_shift == 0) {
            *local_dp++ = (png_byte)local_d;
            local_d = 0;
            local_shift = 6;
        } else {
            local_shift -= 2;
        }

        local_i += png_pass_inc[pass];
    }

    shift = local_shift;
    d = local_d;
    dp = local_dp;
}
