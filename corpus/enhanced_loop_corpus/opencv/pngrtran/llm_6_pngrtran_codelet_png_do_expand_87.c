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
extern png_byte red;
extern png_byte green;
extern png_byte blue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_i;
    for (i = 0; i < row_width; i++) {
        temp_i = row_width - 1 - i;
        png_byte current_sp_val = sp[-(ptrdiff_t)(3 * temp_i + 0)];
        png_byte prev_sp_val1 = sp[-(ptrdiff_t)(3 * temp_i + 1)];
        png_byte prev_sp_val2 = sp[-(ptrdiff_t)(3 * temp_i + 2)];

        if (prev_sp_val2 == red && prev_sp_val1 == green && current_sp_val == blue)
            dp[-(ptrdiff_t)(4 * i + 0)] = 0;
        else
            dp[-(ptrdiff_t)(4 * i + 0)] = 255;

        dp[-(ptrdiff_t)(4 * i + 1)] = current_sp_val;
        dp[-(ptrdiff_t)(4 * i + 2)] = prev_sp_val1;
        dp[-(ptrdiff_t)(4 * i + 3)] = prev_sp_val2;
    }
}
