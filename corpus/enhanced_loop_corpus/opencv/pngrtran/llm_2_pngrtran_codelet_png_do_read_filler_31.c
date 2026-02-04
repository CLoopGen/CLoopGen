#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte hi_filler;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration and pointer arithmetic
    png_bytep local_sp = sp - row_width * 2;
    png_bytep local_dp = dp - row_width * 4;
    for (i = 0; i < row_width; i++) {
        local_dp[4*i + 0] = hi_filler;
        local_dp[4*i + 1] = lo_filler;
        local_dp[4*i + 2] = local_sp[2*i + 1];
        local_dp[4*i + 3] = local_sp[2*i + 0];
    }
}
