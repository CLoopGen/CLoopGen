#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes row_width is even for simplicity and processes two elements at a time
    // to enable consecutive access pattern instead of strided.
    png_bytep sp = row;
    png_bytep dp = row;
    png_uint_32 limit = row_width / 2;

    for (i = 0; i < limit; i++) {
        png_byte save1 = sp[0];
        png_byte save2 = sp[2];
        dp[0] = sp[1];
        dp[1] = save1;
        dp[2] = sp[3];
        dp[3] = save2;
        sp += 4;
        dp += 4;
    }

    // Handle odd case if needed
    if (row_width & 1) {
        png_byte save = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = save;
    }
}
