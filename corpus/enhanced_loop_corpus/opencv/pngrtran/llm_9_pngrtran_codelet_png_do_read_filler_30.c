#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte hi_filler;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified access pattern and modified trip count
    // Effectively doubles the step per iteration, reducing loop trip count by half
    for (i = 1; i < row_width; i += 2) {
        png_byte val1 = *(--sp);
        png_byte val2 = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;
        *(--dp) = val1;
        *(--dp) = val2;

        // Skip second iteration's work if near end
        if (i + 1 >= row_width) break;

        val1 = *(--sp);
        val2 = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;
        *(--dp) = val1;
        *(--dp) = val2;
    }
}
