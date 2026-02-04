#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    png_uint_32 step = 2;
    for (i = 0; i < row_width; i += step) {
        if (i + 1 < row_width) {
            *(--dp) = *(--sp);
            *(--dp) = lo_filler;
            *(--dp) = *(--sp);
            *(--dp) = lo_filler;
        } else {
            *(--dp) = *(--sp);
            *(--dp) = lo_filler;
        }
    }
}
