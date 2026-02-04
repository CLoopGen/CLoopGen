#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // This variant assumes row_width is even for simplicity, processes two elements per iteration
    png_uint_32 limit = (row_width / 2) * 2; // Round down to nearest even number
    for (i = 0; i < limit; i += 2) {
        png_byte value1, value2;
        value1 = (png_byte)(*sp & 15);
        sp++;
        value2 = (png_byte)(*sp & 15);
        sp++;

        v |= (value1 << shift);
        if (shift == 0) {
            *dp = (png_byte)v;
            dp++;
            v = 0;
            shift = 4;
        } else {
            shift -= 4;
        }

        v |= (value2 << shift);
        if (shift == 0) {
            *dp = (png_byte)v;
            dp++;
            v = 0;
            shift = 4;
        } else {
            shift -= 4;
        }
    }
    // Handle leftover element if row_width is odd
    for (; i < row_width; i++) {
        png_byte value;
        value = (png_byte)(*sp & 15);
        v |= (value << shift);
        if (shift == 0) {
            *dp = (png_byte)v;
            dp++;
            v = 0;
            shift = 4;
        } else
            shift -= 4;
        sp++;
    }
}
