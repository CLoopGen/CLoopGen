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
extern png_byte save[2];
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (row_width > 0) {
        i = row_width;
        do {
            save[0] = *(--sp);
            save[1] = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = save[0];
            *(--dp) = save[1];
            i--;
        } while (i > 0);
    }
}
