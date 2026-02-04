#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < row_width; i++) {
        png_bytep temp_sp = row + 2 * i;
        png_bytep temp_dp = row + 2 * i;
        *(temp_dp++) = *temp_sp++;
        *temp_dp = (png_byte)(255 - *temp_sp);
    }
}
