#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte hi_filler;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with index-based addressing (instead of pre-decrement pointer arithmetic)
    png_bytep sp_base = sp - row_width * 6; // Each iteration consumes 6 bytes from sp
    png_bytep dp_base = dp - row_width * 8; // Each iteration produces 8 bytes in dp

    for (i = 0; i < row_width; i++) {
        png_uint_32 src_index = i * 6;
        png_uint_32 dst_index = i * 8;

        dp_base[dst_index + 7] = sp_base[src_index + 5];
        dp_base[dst_index + 6] = sp_base[src_index + 4];
        dp_base[dst_index + 5] = sp_base[src_index + 3];
        dp_base[dst_index + 4] = sp_base[src_index + 2];
        dp_base[dst_index + 3] = sp_base[src_index + 1];
        dp_base[dst_index + 2] = sp_base[src_index + 0];
        dp_base[dst_index + 1] = lo_filler;
        dp_base[dst_index + 0] = hi_filler;
    }
}
