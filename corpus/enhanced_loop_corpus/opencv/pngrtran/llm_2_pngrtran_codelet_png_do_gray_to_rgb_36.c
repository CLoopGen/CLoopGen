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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward pointer arithmetic
    png_bytep temp_sp = sp - row_width + 1;  // Adjust sp to start of segment
    png_bytep temp_dp = dp - 2 * row_width;   // Adjust dp for three writes per iteration

    for (i = 0; i < row_width; i++) {
        png_byte val = *(temp_sp + i);
        *(temp_dp + 3*i)     = val;
        *(temp_dp + 3*i + 1) = val;
        *(temp_dp + 3*i + 2) = val;
    }
}
