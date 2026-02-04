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
    png_uint_32 next_shift;
    png_bytep next_sp = sp;
    for (i = 0; i < row_width; i++) {
        next_shift = (shift == 4) ? 0 : 4;
        value = (*next_sp >> shift) & 15;
        *dp = (png_byte)(value | (value << 4));
        shift = next_shift;
        if (shift == 0)
            next_sp--;
        dp--;
    }
    sp = next_sp;
}
