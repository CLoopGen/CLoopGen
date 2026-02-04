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
    // Variant 2: Strided access with pointer arithmetic unrolled by 2 iterations
    // Increases stride density and reduces conditionals per iteration via partial unrolling
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 step = png_pass_inc[pass];

    // Unroll by two: process two elements per iteration if possible
    for (i = start; i + step < row_width; i += 2 * step) {
        // First element
        sp = row + (size_t)((i) >> 2);
        value = (*sp >> ((3 - (int)(i & 3)) << 1)) & 3;
        d |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift -= 2;
        }

        // Second element
        png_uint_32 i2 = i + step;
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
