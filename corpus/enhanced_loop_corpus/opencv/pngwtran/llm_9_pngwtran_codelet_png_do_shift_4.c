#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift_start[4];
extern int shift_dec[4];
extern unsigned int channels;
extern png_bytep bp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational complexity: eliminate inner loop entirely, replace with direct computation
    // Also reduce trip count by processing every other element
    for (i = 0; i < istop; i += 2, bp += 2) {
        unsigned int c = i % channels;
        unsigned int v = *bp;
        unsigned int out;

        // Direct bit manipulation without loop: single shift based on start value only
        if (shift_start[c] > 0)
            out = v << shift_start[c];
        else
            out = v >> (-shift_start[c]);

        *bp = (png_byte)(out & 255);
    }
}
