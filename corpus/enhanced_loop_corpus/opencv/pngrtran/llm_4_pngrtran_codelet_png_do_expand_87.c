#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red;
extern png_byte green;
extern png_byte blue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row_width; i++) {
    *dp-- = (*(sp - 2) == red && *(sp - 1) == green && *(sp) == blue) ? 0 : 255;
    *dp-- = *sp--;
    *dp-- = *sp--;
    *dp-- = *sp--;
}
}
