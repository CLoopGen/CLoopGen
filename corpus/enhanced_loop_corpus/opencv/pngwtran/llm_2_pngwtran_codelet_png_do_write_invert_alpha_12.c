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
for (i = 0 , sp = dp = row; i < row_width; i++) {
    png_bytep current_src = sp + 2 * i;
    png_bytep current_dst = dp + 2 * i;
    *(current_dst) = *(current_src);
    *(current_dst + 1) = (png_byte)(255 - *(current_src + 1));
}
}
