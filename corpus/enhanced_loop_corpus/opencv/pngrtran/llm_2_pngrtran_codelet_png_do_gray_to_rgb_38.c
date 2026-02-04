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
    // Instead of decrementing pointers, use index-based consecutive access
    for (i = 0; i < row_width; i++) {
        png_bytep base_sp = sp - i * 4;  // Simulate backward source start
        png_bytep base_dp = dp - i * 4;  // Simulate backward dest start
        base_dp[0] = base_sp[0];
        base_dp[1] = base_sp[1];
        base_dp[2] = base_sp[2];
        base_dp[3] = base_sp[3];
    }
}
