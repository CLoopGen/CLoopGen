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
    // Variant 2: Reduced loop nesting depth — but since original is a single loop, we simulate "reduction" 
    // by unrolling the loop body to process two iterations per loop step, reducing effective loop count.
    // This decreases loop control overhead and increases instruction-level parallelism.

    png_uint_32 start = png_pass_start[pass];
    png_uint_32 inc = png_pass_inc[pass];
    png_uint_32 i1, i2;

    for (i = start; i < row_width; i += 2 * inc) {
        // First iteration of unrolled pair
        i1 = i;
        sp = row + (size_t)(i1 >> 1);
        value = (*sp >> ((1 - (int)(i1 & 1)) << 2)) & 15;
        d |= (value << shift);
        if (shift == 0) {
            shift = 4;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift -= 4;
        }

        // Second iteration, if within bounds
        i2 = i + inc;
        if (i2 >= row_width) break;

        sp = row + (size_t)(i2 >> 1);
        value = (*sp >> ((1 - (int)(i2 & 1)) << 2)) & 15;
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
