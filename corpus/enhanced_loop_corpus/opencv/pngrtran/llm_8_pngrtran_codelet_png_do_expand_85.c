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
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_i;
    png_bytep temp_sp = sp;
    png_bytep temp_dp = dp;
    for (i = 0; i < row_width; i++) {
        temp_i = i;
        if ((*(temp_sp - temp_i) & 255U) == gray)
            *(temp_dp - 3 * temp_i - 0) = 0;
        else
            *(temp_dp - 3 * temp_i - 0) = 255;
        *(temp_dp - 3 * temp_i - 1) = *(temp_sp - temp_i);
    }
    sp = temp_sp - row_width;
    dp = temp_dp - 3 * row_width;
}
