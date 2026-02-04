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
    if (row_width > 0) {
        for (i = 0; i < row_width; i += 2) {
            png_uint_32 end_i = i + 1;
            save = *(--sp);
            *(--dp) = *(--sp);
            *(--dp) = save;

            if (end_i < row_width) {
                save = *(--sp);
                *(--dp) = *(--sp);
                *(--dp) = save;
            }
        }
    }
}
