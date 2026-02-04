#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row_width; i++) {
    int bit = (*sp >> shift) & 1;
    *dp = bit << 8 | bit << 7 | bit << 6 | bit << 5 | bit << 4 | bit << 3 | bit << 2 | bit << 1 | bit;
    shift++;
    if (shift >= 8) {
        shift = 0;
        sp--;
    }
    dp--;
}
}
