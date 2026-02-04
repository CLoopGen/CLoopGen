#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward indexing (reversed logic to maintain correctness)
    png_bytep temp_sp = sp - 2 * row_width;
    png_bytep temp_dp = dp - 2 * row_width;
    
    for (i = 0; i < row_width; i++) {
        temp_dp[2*i + 0] = (png_byte)(255 - temp_sp[2*i + 1]);
        temp_dp[2*i + 1] = temp_sp[2*i + 0];
    }
}
