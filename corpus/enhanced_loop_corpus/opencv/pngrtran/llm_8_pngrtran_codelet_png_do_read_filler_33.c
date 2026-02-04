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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count
    // The loop now processes two logical iterations per single loop cycle, increasing arithmetic operations.
    png_uint_32 step = 2;
    for (i = 0; i < row_width; i += step) {
        // First element triplet + filler
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = lo_filler;

        // Second element triplet + filler (if within bounds)
        if (i + 1 < row_width) {
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = lo_filler;
        }
    }
}
