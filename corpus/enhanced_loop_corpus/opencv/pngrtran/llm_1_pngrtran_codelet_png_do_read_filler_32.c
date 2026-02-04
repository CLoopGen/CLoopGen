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
    if (row_width > 1) {
        i = 1;
        for (; i < row_width; i += 2) {  // Loop unrolling attempt with reduced effective iterations (depth decreased in effect via stride)
            *(--dp) = lo_filler;
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);

            if (i + 1 < row_width) {  // Simulate second iteration of original loop
                *(--dp) = lo_filler;
                *(--dp) = *(--sp);
                *(--dp) = *(--sp);
                *(--dp) = *(--sp);
            }
        }
    }
}
