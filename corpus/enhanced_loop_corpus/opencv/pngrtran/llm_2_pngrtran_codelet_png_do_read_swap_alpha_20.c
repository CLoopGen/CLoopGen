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
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with forward indexing (reversed logic to maintain correctness)
    png_bytep s_end = sp - row_width * 4;
    png_bytep d_end = dp - row_width * 4;
    png_uint_32 j;

    for (j = 0; j < row_width; j++) {
        sp -= 4;
        dp -= 4;
        png_byte b0 = sp[0];
        png_byte b1 = sp[1];
        png_byte b2 = sp[2];
        png_byte b3 = sp[3];
        dp[3] = b0;
        dp[2] = b1;
        dp[1] = b2;
        dp[0] = b3;
    }

    sp = s_end;
    dp = d_end;
}
