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
    // Variant 1: Consecutive memory access by precomputing addresses with forward traversal
    png_bytep s_end = sp - (row_width - 1);  // Target final source position
    for (i = 0; i < row_width; i++) {
        *dp = (png_byte)((*sp >> shift) & 1);
        sp--;  // Move source pointer consecutively backward
        dp--;  // Move destination pointer consecutively backward
        shift = (shift == 7) ? 0 : shift + 1;
    }
}
