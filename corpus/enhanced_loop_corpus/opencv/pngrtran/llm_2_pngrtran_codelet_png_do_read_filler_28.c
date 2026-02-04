#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward indexing (reversed logic using offset-based arithmetic)
    png_bytep dp_offset = dp - 2 * (row_width - 1);
    png_bytep sp_offset = sp - (row_width - 1);
    for (i = 1; i < row_width; i++) {
        dp_offset[2*i - 2] = lo_filler;
        dp_offset[2*i - 1] = sp_offset[i - 1];
    }
}
