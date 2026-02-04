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
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward pointer traversal
    png_bytep sp_local = sp - row_width + 1;  // Adjust to start of segment
    png_bytep dp_local = dp - 2 * row_width + 1;
    for (i = 0; i < row_width; i++) {
        png_byte val = sp_local[i];
        if ((val & 255U) == gray)
            dp_local[2*i] = 0;
        else
            dp_local[2*i] = 255;
        dp_local[2*i + 1] = val;
    }
    sp = sp_local + row_width - 1;
    dp = dp_local + 2 * row_width - 1;
}
