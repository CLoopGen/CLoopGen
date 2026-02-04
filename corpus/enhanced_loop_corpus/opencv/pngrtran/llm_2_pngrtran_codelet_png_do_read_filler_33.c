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



void loop() {
    // Variant 1: Consecutive memory access with forward indexing (using pointer arithmetic from base)
    png_bytep dp_base = dp - row_width * 4;
    png_bytep sp_base = sp - row_width * 3;
    
    for (i = 0; i < row_width; i++) {
        png_uint_32 src_offset = i * 3;
        png_uint_32 dst_offset = i * 4;

        dp_base[dst_offset + 0] = sp_base[src_offset + 0];
        dp_base[dst_offset + 1] = sp_base[src_offset + 1];
        dp_base[dst_offset + 2] = sp_base[src_offset + 2];
        dp_base[dst_offset + 3] = lo_filler;
    }
}
