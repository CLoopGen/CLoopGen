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
    png_uint_32 start = png_pass_start[pass];
    png_uint_32 inc = png_pass_inc[pass];
    for (i = start; i + 4 < row_width; i += inc * 4) {
        for (int j = 0; j < 4 && (i + j * inc) < row_width; ++j) {
            png_uint_32 idx = i + j * inc;
            sp = row + (size_t)(idx >> 3);
            value = (int)(*sp >> (7 - (int)(idx & 7))) & 1;
            d |= (value << shift);
            if (shift == 0) {
                shift = 7;
                *dp++ = (png_byte)d;
                d = 0;
            } else {
                shift--;
            }
        }
    }
    for (; i < row_width; i += inc) {
        sp = row + (size_t)(i >> 3);
        value = (int)(*sp >> (7 - (int)(i & 7))) & 1;
        d |= (value << shift);
        if (shift == 0) {
            shift = 7;
            *dp++ = (png_byte)d;
            d = 0;
        } else {
            shift--;
        }
    }
}
