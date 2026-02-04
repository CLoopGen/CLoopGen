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
    // Variant 1: Increased computational intensity by unrolling the loop 2x and reducing trip count accordingly.
    // This reduces loop overhead and increases arithmetic per iteration.
    png_uint_32 inc = png_pass_inc[pass];
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 limit = row_width - inc;  // Ensure safe unrolling

    for (i = start; i < limit; i += 2 * inc) {
        // First iteration of unrolled pair
        sp = row + (size_t)(i >> 2);
        value = (*sp >> ((3 - (int)(i & 3)) << 1)) & 3;
        d |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift -= 2;
        }

        // Second iteration of unrolled pair
        png_uint_32 i2 = i + inc;
        sp = row + (size_t)(i2 >> 2);
        value = (*sp >> ((3 - (int)(i2 & 3)) << 1)) & 3;
        d |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift -= 2;
        }
    }

    // Handle remaining element if any
    if (i < row_width) {
        sp = row + (size_t)(i >> 2);
        value = (*sp >> ((3 - (int)(i & 3)) << 1)) & 3;
        d |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift -= 2;
        }
    }
}
