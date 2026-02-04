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
    // Variant 1: Consecutive memory access with forward indexing (reversed traversal using offset arithmetic)
    png_bytep dp_base = dp - 4 * (row_width - 1);
    png_bytep sp_base = sp - 3 * (row_width - 1);
    for (i = 0; i < row_width - 1; i++) {
        png_uint_32 dp_offset = 4 * i;
        png_uint_32 sp_offset = 3 * i;
        dp_base[dp_offset + 0] = lo_filler;
        dp_base[dp_offset + 1] = sp_base[sp_offset + 0];
        dp_base[dp_offset + 2] = sp_base[sp_offset + 1];
        dp_base[dp_offset + 3] = sp_base[sp_offset + 2];
    }
    // Update global pointers to reflect final positions
    dp = dp_base + 4 * (row_width - 1);
    sp = sp_base + 3 * (row_width - 1);
}
