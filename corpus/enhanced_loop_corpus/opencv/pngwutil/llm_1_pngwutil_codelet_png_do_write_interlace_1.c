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
    // Variant 2: Decreased effective nesting depth by eliminating the single loop and unrolling it partially.
    // A single loop with unrolled body to process up to 4 iterations per step, reducing loop control overhead.
    // Residual iterations are handled via a secondary bounded loop.
    png_uint_32 inc = png_pass_inc[pass];
    png_uint_32 start = png_pass_start[pass];
    i = start;

    // Main loop unrolled by factor of 4
    while (i + 3 * inc < row_width) {
        // Unroll 4 iterations
        for (int unroll = 0; unroll < 4; ++unroll) {
            sp = row + (size_t)(i >> 3);
            value = (int)(*sp >> (7 - (int)(i & 7))) & 1;
            d |= (value << shift);
            if (shift == 0) {
                shift = 7;
                *dp++ = (png_byte)d;
                d = 0;
            } else
                shift--;
            i += inc;
        }
    }

    // Handle remaining elements with original logic
    for (; i < row_width; i += inc) {
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
