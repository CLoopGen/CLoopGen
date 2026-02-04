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
for (i = png_pass_start[pass]; i < row_width; i += png_pass_inc[pass]) {
    sp = row + (size_t)(i >> 2);
    value = (*sp >> ((3 - (int)(i & 3)) << 1)) & 3;
    d |= (value << shift);
    shift = (shift == 0) ? 6 : shift - 2;
    *dp = (png_byte)d;
    dp += (shift == 6);
    d *= (shift != 6); // Reset d only when we store
}
}
