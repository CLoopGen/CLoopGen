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
extern png_byte red;
extern png_byte green;
extern png_byte blue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop 2x and adding redundant comparisons
    // Trip count reduced by half with more operations per iteration
    png_uint_32 limit = row_width / 2;
    for (i = 0; i < limit; i++) {
        // First triplet
        png_byte s0 = *(sp - 0);
        png_byte s1 = *(sp - 1);
        png_byte s2 = *(sp - 2);
        if (s2 == red && s1 == green && s0 == blue)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = s0;
        *dp-- = s1;
        *dp-- = s2;
        
        sp -= 3;

        // Second triplet, if available
        if (i * 2 + 1 < row_width) {
            s0 = *(sp - 0);
            s1 = *(sp - 1);
            s2 = *(sp - 2);
            if (s2 == red && s1 == green && s0 == blue)
                *dp-- = 0;
            else
                *dp-- = 255;
            *dp-- = s0;
            *dp-- = s1;
            *dp-- = s2;
            
            sp -= 3;
        }
    }

    // Handle remaining elements if row_width is odd
    if (row_width % 2 == 1) {
        if (*(sp - 2) == red && *(sp - 1) == green && *(sp) == blue)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
    }
}
