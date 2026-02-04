#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width; i += 2) {
        if (i + 1 < row_width) {
            png_byte s1_next = *(--sp);
            *(--dp) = (png_byte)(255 - s1_next);
            png_byte s2_next = *(--sp);
            *(--dp) = s2_next;

            png_byte s1_curr = *(--sp);
            *(--dp) = (png_byte)(255 - s1_curr);
            png_byte s2_curr = *(--sp);
            *(--dp) = s2_curr;
        } else {
            *(--dp) = (png_byte)(255 - *(--sp));
            *(--dp) = *(--sp);
        }
    }
}
