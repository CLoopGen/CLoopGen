#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_byte green_high;
extern png_byte blue_high;
extern png_byte red_low;
extern png_byte green_low;
extern png_byte blue_low;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red_high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row_width; i++) {
    *dp-- = (*(sp - 5) == red_high) ? 0 : 255;
    *dp-- = (*(sp - 4) == red_low &&
             *(sp - 3) == green_high &&
             *(sp - 2) == green_low &&
             *(sp - 1) == blue_high &&
             *(sp) == blue_low) ? 0 : 255;

    *dp-- = *sp--;
    *dp-- = *sp--;
    *dp-- = *sp--;
    *dp-- = *sp--;
    *dp-- = *sp--;
    *dp-- = *sp--;
}
}
