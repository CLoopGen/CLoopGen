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
    // Variant 2: Reduced trip count with conditional overhead and stride adjustment
    // Loop runs every 4th index, simulating decimation, but applies more operations per iteration.
    // Trip count is effectively divided by 4, but each iteration performs expanded writes.
    const png_uint_32 stride = 4;
    png_uint_32 limit = row_width / stride;
    for (i = 0; i < limit; i++) {
        // Perform original operation four times per iteration
        for (png_uint_32 j = 0; j < 4; j++) {
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = lo_filler;
        }
    }
}
