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
    // Instead of decrementing pointers, use index-based access from the end
    png_bytep base_sp = sp - row_width * 4;  // Assuming 4 bytes per pixel, adjust origin
    png_bytep base_dp = dp - row_width * 4;

    for (i = 0; i < row_width; i++) {
        png_uint_32 idx = row_width - 1 - i;  // Reverse iteration index
        png_uint_32 offset = idx * 4;

        base_dp[offset + 3] = (png_byte)(255 - base_sp[offset + 3]);
        base_dp[offset + 2] = (png_byte)(255 - base_sp[offset + 2]);
    }
}
