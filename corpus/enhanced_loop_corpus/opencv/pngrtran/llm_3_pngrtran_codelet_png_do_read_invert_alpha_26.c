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
    // Variant 2: Strided memory access – process every second element in reverse order, then the odd positions
    png_uint_32 step = 2;
    png_bytep base_sp = sp - 2 * row_width;
    png_bytep base_dp = dp - 2 * row_width;

    // First pass: handle even indices with stride
    for (i = 0; i < row_width; i += step) {
        base_dp[2*(row_width - 1 - i) + 0] = (png_byte)(255 - base_sp[2*(row_width - 1 - i) + 1]);
        base_dp[2*(row_width - 1 - i) + 1] = base_sp[2*(row_width - 1 - i) + 0];
    }
    // Second pass: fill in remaining positions (odd strides if any, though here step=2 covers all due to loop bound)
    for (i = 1; i < row_width; i += step) {
        base_dp[2*(row_width - 1 - i) + 0] = (png_byte)(255 - base_sp[2*(row_width - 1 - i) + 1]);
        base_dp[2*(row_width - 1 - i) + 1] = base_sp[2*(row_width - 1 - i) + 0];
    }
}
