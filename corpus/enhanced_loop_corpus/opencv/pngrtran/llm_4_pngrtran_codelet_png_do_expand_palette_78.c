#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal and pre-increment
    png_bytep temp_sp = sp - (row_width - 1);  // Adjust sp to start of block
    png_bytep temp_dp = dp - (row_width - 1);  // Adjust dp to start of block
    shift = (shift + 2 * (row_width % 4)) % 8;  // Simulate accumulated shift effect
    for (i = 0; i < row_width; i++) {
        value = (temp_sp[i] >> shift) & 3;
        temp_dp[i] = (png_byte)value;
        shift = (shift == 6) ? 0 : shift + 2;
    }
}
