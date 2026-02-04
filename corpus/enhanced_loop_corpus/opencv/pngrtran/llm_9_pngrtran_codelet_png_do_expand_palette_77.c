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
    // Variant 2: Reduced computational intensity with simplified control flow
    // Trip count remains same, but conditional updates are replaced with arithmetic
    for (i = 0; i < row_width; i++) {
        *dp = (png_byte)((*sp >> shift) & 1);  // Direct assignment using cast

        // Use arithmetic instead of branching for shift and pointer update
        shift++;
        sp -= (shift >> 3);        // Subtract 1 when shift becomes 8 (i.e., after shift==7)
        shift &= 7;                // Equivalent to: shift = shift % 8, keeps shift in [0,7]
        dp--;
    }
}
