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



void loop(){
    png_bytep temp_sp;
    for (i = 0, sp = dp = row; i < row_width; i++) {
        temp_sp = sp + 6;
        dp = temp_sp;
        *(dp++) = (png_byte)(255 - *(++temp_sp));
        *dp = (png_byte)(255 - *(++temp_sp));
    }
}
