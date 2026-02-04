#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-increment pattern
    // Instead of decrementing dp and conditionally decrementing sp,
    // we reverse the iteration order and access sp and dp consecutively upward.
    png_bytep base_sp = sp - (row_width - 1); // Adjust base so that we can go forward
    png_bytep base_dp = dp - (row_width - 1);
    for (i = 0; i < row_width; i++) {
        png_bytep current_sp = base_sp + i;
        png_bytep current_dp = base_dp + i;
        int current_shift = (shift + i) % 8;
        if ((*current_sp >> current_shift) & 1)
            *current_dp = 255;
        else
            *current_dp = 0;
    }
    // Update global shift state after loop
    shift = (shift + row_width) % 8;
    // Adjust sp and dp to reflect final position as in original
    sp = base_sp + (row_width - 1);
    dp = base_dp + (row_width - 1);
}
