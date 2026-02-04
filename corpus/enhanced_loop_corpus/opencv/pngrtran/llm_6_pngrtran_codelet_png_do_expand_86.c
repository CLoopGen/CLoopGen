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
extern unsigned int gray_high;
extern unsigned int gray_low;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_i;
    png_byte val_current, val_prev;
    png_byte temp_dp[4];
    for (i = 0; i < row_width; i++) {
        val_prev = *(sp - 1) & 255U;
        val_current = *sp & 255U;
        temp_i = i;

        if (val_prev == gray_high && val_current == gray_low) {
            temp_dp[0] = 0;
            temp_dp[1] = 0;
        } else {
            temp_dp[0] = 255;
            temp_dp[1] = 255;
        }

        temp_dp[2] = *(sp);
        temp_dp[3] = *(sp - 1);

        *(dp - 3) = temp_dp[0];
        *(dp - 2) = temp_dp[1];
        *(dp - 1) = temp_dp[2];
        *dp = temp_dp[3];

        dp -= 4;
        sp -= 2;
    }
}
