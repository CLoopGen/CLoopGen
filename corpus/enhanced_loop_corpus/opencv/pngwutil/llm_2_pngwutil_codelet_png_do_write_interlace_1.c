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
    // Variant 1: Consecutive memory access with precomputed pointer bounds
    png_bytep sp_start = row + (size_t)(png_pass_start[pass] >> 3);
    png_bytep sp_end = row + (size_t)((row_width + 7) >> 3);
    size_t current_bit_offset = png_pass_start[pass] & 7;
    sp = sp_start;
    
    for (; sp < sp_end; sp++) {
        png_byte current_byte = *sp;
        for (int bit_in_byte = (sp == sp_start ? current_bit_offset : 0); 
             bit_in_byte < 8; bit_in_byte++) {
            png_uint_32 i = ((sp - row) << 3) + bit_in_byte;
            if (i >= row_width) break;

            value = (int)(current_byte >> (7 - bit_in_byte)) & 1;
            d |= (value << shift);
            if (shift == 0) {
                *dp++ = (png_byte)d;
                d = 0;
                shift = 7;
            } else {
                shift--;
            }
        }
    }
}
