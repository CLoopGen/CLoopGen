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
    png_byte cache1, cache2, cache3, cache4, cache5, cache6;
    for (i = 0; i < row_width; i++) {
        cache1 = *(--sp);
        cache2 = *(--sp);
        cache3 = *(--sp);
        cache4 = *(--sp);
        cache5 = *(--sp);
        cache6 = *(--sp);

        *(--dp) = hi_filler;
        *(--dp) = lo_filler;
        *(--dp) = cache6;
        *(--dp) = cache5;
        *(--dp) = cache4;
        *(--dp) = cache3;
        *(--dp) = cache2;
        *(--dp) = cache1;
    }
}
