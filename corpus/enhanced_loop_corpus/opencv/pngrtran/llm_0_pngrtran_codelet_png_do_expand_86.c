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
extern unsigned int gray_high;
extern unsigned int gray_low;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 i;
    for (i = 0; i < row_width; i++) {
        {
            if ((*(sp - 1) & 255U) == gray_high && (*(sp) & 255U) == gray_low) {
                *dp-- = 0;
                *dp-- = 0;
            } else {
                *dp-- = 255;
                *dp-- = 255;
            }
            *dp-- = *sp--;
            *dp-- = *sp--;
        }
    }
}
