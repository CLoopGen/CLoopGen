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
    // Variant 1: Consecutive memory access with forward indexing
    // Instead of decrementing pointers inside the loop, we calculate indices upfront
    // and access elements consecutively from base pointers.
    png_bytep base_sp = sp - row_width * 8 + 1;  // Adjust base to accommodate all reads
    png_bytep base_dp = dp - row_width * 8 + 1;
    
    for (i = 0; i < row_width; i++) {
        png_uint_32 offset = i * 8;
        base_dp[offset + 0] = base_sp[offset + 0];
        base_dp[offset + 1] = base_sp[offset + 1];
        base_dp[offset + 2] = base_sp[offset + 2];
        base_dp[offset + 3] = base_sp[offset + 3];
        base_dp[offset + 4] = base_sp[offset + 4];
        base_dp[offset + 5] = base_sp[offset + 5];
        base_dp[offset + 6] = base_sp[offset + 6];
        base_dp[offset + 7] = base_sp[offset + 7];
    }
}
