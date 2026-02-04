#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 4;
    png_uint_32 limit = row_width - (row_width % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        for (int j = 0; j < unroll_factor; j++) {
            value = (*sp >> shift) & 15;
            *dp = (png_byte)(value | (value << 4));
            if (shift == 4) {
                shift = 0;
                sp--;
            } else {
                shift = 4;
            }
            dp--;
        }
    }
    for (; i < row_width; i++) {
        value = (*sp >> shift) & 15;
        *dp = (png_byte)(value | (value << 4));
        if (shift == 4) {
            shift = 0;
            sp--;
        } else
            shift = 4;
        dp--;
    }
}
