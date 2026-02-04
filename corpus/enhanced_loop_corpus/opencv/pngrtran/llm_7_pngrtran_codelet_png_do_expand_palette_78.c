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
for (i = 0; i < row_width; i++) {
    value = (*sp >> shift) & 3;
    *dp = (png_byte)value;
    dp--;
    shift += 2;
    sp -= (shift >> 3); // Equivalent to sp-- when shift >= 8, but here shift resets logically at 6
    shift &= 7; // Keep shift within 0-7 range
    shift ^= ((shift >> 3) << 3); // Manual reset: clears bits if shift was 8, maps 8->0
}
}
