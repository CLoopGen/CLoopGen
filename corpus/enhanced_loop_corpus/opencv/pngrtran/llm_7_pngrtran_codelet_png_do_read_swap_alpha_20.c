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
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_byte local_save;
    for (i = 0; i < row_width; i++) {
        local_save = *(--sp);
        *(--dp) = local_save;
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
    }
    if (row_width > 0) {
        dp += 4 * row_width - 1;
        sp += 4 * row_width - 1;
    }
}
