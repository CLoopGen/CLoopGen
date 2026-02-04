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
    for (i = 0; i < row_width; i += 2) {
        png_byte s1 = *(sp - (shift == 4 ? 1 : 0));
        png_byte s2 = *(sp - 1);
        value = (s1 >> shift) & 15;
        *dp = (png_byte)(value | (value << 4));
        dp--;
        if (i + 1 < row_width) {
            value = (s2 >> 4) & 15;
            *dp = (png_byte)(value | (value << 4));
            dp--;
        }
        shift = (shift == 0) ? 4 : 0;
        sp -= (shift == 0) ? 1 : 0;
    }
}
