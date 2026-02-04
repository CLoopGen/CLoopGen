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
    // Variant 1: Increased computational intensity by unrolling the loop and reducing trip count.
    // This reduces loop overhead and increases arithmetic per iteration.
    png_uint_32 inc = png_pass_inc[pass];
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 end = row_width - (row_width % inc) + ((row_width % inc) ? inc : 0); // Align to multiple of inc

    for (i = start; i < end; i += 4 * inc) {
        // Unroll 4 iterations
        if (i >= row_width) break;
        sp = row + (size_t)(i >> 1);
        value = (*sp >> ((1 - (int)(i & 1)) << 2)) & 15;
        d |= (value << shift);
        if (shift == 0) {
            *dp++ = (png_byte)d;
            d = 0;
            shift = 4;
        } else {
            shift -= 4;
        }

        png_uint_32 j = i + inc;
        if (j >= row_width) continue;
        sp = row + (size_t)(j >> 1);
        value = (*sp >> ((1 - (int)(j & 1)) << 2)) & 15;
        d |= (value << shift);
        if (shift == 0) {
            *dp++ = (png_byte)d;
            d = 0;
            shift = 4;
        } else {
            shift -= 4;
        }

        j = i + 2 * inc;
        if (j >= row_width) continue;
        sp = row + (size_t)(j >> 1);
        value = (*sp >> ((1 - (int)(j & 1)) << 2)) & 15;
        d |= (value << shift);
        if (shift == 0) {
            *dp++ = (png_byte)d;
            d = 0;
            shift = 4;
        } else {
            shift -= 4;
        }

        j = i + 3 * inc;
        if (j >= row_width) continue;
        sp = row + (size_t)(j >> 1);
        value = (*sp >> ((1 - (int)(j & 1)) << 2)) & 15;
        d |= (value << shift);
        if (shift == 0) {
            *dp++ = (png_byte)d;
            d = 0;
            shift = 4;
        } else {
            shift -= 4;
        }
    }
}
