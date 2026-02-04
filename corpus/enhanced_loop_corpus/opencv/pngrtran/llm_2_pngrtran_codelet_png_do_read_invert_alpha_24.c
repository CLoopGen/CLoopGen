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
    // Variant 1: Consecutive memory access with forward indexing
    png_bytep temp_sp = sp - row_width * 4; // Adjust starting point for consecutive read
    png_bytep temp_dp = dp - row_width * 4; // Adjust starting point for consecutive write
    for (i = 0; i < row_width; i++) {
        temp_dp[i] = (png_byte)(255 - temp_sp[i * 4]); // Stride of 4 on source, but written consecutively
    }
}
