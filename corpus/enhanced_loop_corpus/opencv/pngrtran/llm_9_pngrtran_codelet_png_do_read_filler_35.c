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
    for (i = 0; i < row_width / 4; i++) {
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;

        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;

        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;

        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = lo_filler;
        *(--dp) = hi_filler;
    }
}
