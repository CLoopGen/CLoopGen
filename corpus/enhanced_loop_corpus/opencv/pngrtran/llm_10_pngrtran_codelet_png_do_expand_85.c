#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2) and additional arithmetic operations
    png_uint_32 limit = row_width - (row_width % 2);
    for (i = 0; i < limit; i += 2) {
        png_byte val1 = sp[0];
        png_byte val2 = sp[-1];

        // Additional arithmetic: use XOR with gray instead of direct comparison
        *dp-- = ((val1 & 255U) ^ gray) ? 255 : 0;
        *dp-- = val1;
        *dp-- = ((val2 & 255U) ^ gray) ? 255 : 0;
        *dp-- = val2;

        sp -= 2;
    }
    // Handle remaining element if row_width is odd
    if (row_width % 2 == 1) {
        if ((*sp & 255U) == gray)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;
    }
}
