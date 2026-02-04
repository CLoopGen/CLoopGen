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
    // Instead of decrementing pointers, use index-based consecutive access
    // This changes the pattern from reverse traversal to forward traversal
    png_bytep base_sp = sp - row_width * 8 + 1;  // Adjust base so that i=0 maps to original --sp chain
    png_bytep base_dp = dp - row_width * 2 + 1;
    
    for (i = 0; i < row_width; i++) {
        png_uint_32 offset = i * 8;
        base_dp[i * 2]     = (png_byte)(255 - base_sp[offset]);
        base_dp[i * 2 + 1] = (png_byte)(255 - base_sp[offset + 1]);
    }
}
