#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row_width; i++) {
    png_byte temp = *sp;
    *dp = (png_byte)((temp >> shift) & 3);
    dp--;
    shift = (shift == 6) ? 0 : shift + 2;
    if (shift == 0)
        sp--;
}
}
