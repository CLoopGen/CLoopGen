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



void loop() {
    // Variant 1: Increased loop nesting depth by splitting the original loop into two levels.
    // The outer loop handles pass segments in chunks, and the inner loop processes individual elements.
    png_uint_32 chunk_size = 16;
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 inc = png_pass_inc[pass];

    for (png_uint_32 base = start; base < row_width; base += chunk_size * inc) {
        for (i = base; i < row_width && i < base + chunk_size * inc; i += inc) {
            sp = row + (size_t)(i >> 1);
            value = (*sp >> ((1 - (int)(i & 1)) << 2)) & 15;
            d |= (value << shift);
            if (shift == 0) {
                shift = 4;
                *dp++ = (png_byte)d;
                d = 0;
            } else {
                shift -= 4;
            }
        }
    }
}
