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
    // Variant 1: Consecutive memory access with index remapping
    // Instead of strided access via png_pass_inc, iterate consecutively and map index
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 step = png_pass_inc[pass];
    png_uint_32 count = (row_width - start + step - 1) / step;
    
    for (i = 0; i < count; i++) {
        png_uint_32 mapped_i = start + i * step;
        sp = row + (size_t)(mapped_i >> 1);
        value = (*sp >> ((1 - (int)(mapped_i & 1)) << 2)) & 15;
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
