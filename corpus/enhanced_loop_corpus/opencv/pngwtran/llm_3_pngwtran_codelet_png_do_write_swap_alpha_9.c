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
    png_byte save[2];
    ptrdiff_t offset = i * 4;
    save[0] = *(sp + offset + 0);
    save[1] = *(sp + offset + 1);
    *(dp + offset + 0) = *(sp + offset + 2);
    *(dp + offset + 1) = *(sp + offset + 3);
    *(dp + offset + 2) = save[0];
    *(dp + offset + 3) = save[1];
}
}
