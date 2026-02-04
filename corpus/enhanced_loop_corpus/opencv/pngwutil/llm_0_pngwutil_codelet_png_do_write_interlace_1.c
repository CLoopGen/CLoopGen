#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern  png_byte png_pass_start[7];
extern  png_byte png_pass_inc[7];
extern png_bytep row;
extern int pass;
extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int d;
extern int value;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops.
    // Outer loop handles block-wise traversal, inner loop processes individual elements within block.
    png_uint_32 block_size = 64;
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 inc = png_pass_inc[pass];
    png_uint_32 end_block_start = ((row_width - start + inc - 1) / inc) * inc + start;
    
    for (png_uint_32 block_start = start; block_start < end_block_start; block_start += block_size * inc) {
        for (i = block_start; i < row_width && i < block_start + block_size * inc; i += inc) {
            sp = row + (size_t)(i >> 3);
            value = (int)(*sp >> (7 - (int)(i & 7))) & 1;
            d |= (value << shift);
            if (shift == 0) {
                shift = 7;
                *dp++ = (png_byte)d;
                d = 0;
            } else
                shift--;
        }
    }
}
