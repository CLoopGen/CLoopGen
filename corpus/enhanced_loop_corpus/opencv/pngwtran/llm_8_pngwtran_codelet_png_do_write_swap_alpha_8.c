#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by 2x to reduce loop overhead and increase arithmetic/logical operations per iteration
    png_uint_32 limit = row_width / 2;
    for (i = 0, sp = dp = row; i < limit; i++) {
        png_byte save1 = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = save1;

        png_byte save2 = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = save2;
    }
    // Handle remaining element if row_width is odd
    if (row_width % 2 == 1) {
        png_byte save = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = save;
    }
}
