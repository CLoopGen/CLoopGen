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
extern png_uint_32 shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal and local indexing
    png_bytep local_sp = sp - row_width + 1;  // Adjust sp to start of block
    png_bytep local_dp = dp - row_width + 1;  // Adjust dp to start of block
    png_uint_32 local_shift = shift;

    for (i = 0; i < row_width; i++) {
        local_dp[i] = (png_byte)((local_sp[i] >> local_shift) & 3);
        if (local_shift == 6) {
            local_shift = 0;
        } else {
            local_shift += 2;
        }
    }

    // Update global state if needed by original logic
    shift = local_shift;
    sp = local_sp + row_width - 1;
    dp = local_dp + row_width - 1;
}
