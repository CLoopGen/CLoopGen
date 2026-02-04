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
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    png_uint_32 j;
    for (j = 0; j < row_width; j++) {
        png_byte prev = *(local_sp - 1) & 255U;
        png_byte curr = *local_sp & 255U;
        int match = (prev == gray_high && curr == gray_low);

        *(local_dp - 3) = match ? 0 : 255;
        *(local_dp - 2) = match ? 0 : 255;
        *(local_dp - 1) = *local_sp;
        *local_dp = *(local_sp - 1);

        local_dp -= 4;
        local_sp -= 2;
    }
    sp = local_sp;
    dp = local_dp;
}
