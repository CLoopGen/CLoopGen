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
    // Variant 1: Increased computational intensity with unrolled iterations and reduced trip count
    png_uint_32 step = 4;
    for (i = 4; i < row_width; i += step) {
        // Unroll four operations into one iteration, each handling three bytes from sp and one filler
        *(--dp) = lo_filler; *(--dp) = *(--sp); *(--dp) = *(--sp); *(--dp) = *(--sp);
        *(--dp) = lo_filler; *(--dp) = *(--sp); *(--dp) = *(--sp); *(--dp) = *(--sp);
        *(--dp) = lo_filler; *(--dp) = *(--sp); *(--dp) = *(--sp); *(--dp) = *(--sp);
        *(--dp) = lo_filler; *(--dp) = *(--sp); *(--dp) = *(--sp); *(--dp) = *(--sp);
    }
    // Handle remaining elements not covered by full unrolling steps
    for (; i < row_width; i++) {
        *(--dp) = lo_filler;
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
    }
}
