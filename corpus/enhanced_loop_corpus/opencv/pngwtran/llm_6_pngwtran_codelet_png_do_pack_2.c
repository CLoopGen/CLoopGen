#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_value = 0;
    for (i = 0; i < row_width; i++) {
        png_byte value;
        value = (png_byte)((*sp) & 15);
        temp_value |= (value << shift);
        if (shift == 0) {
            *dp = (png_byte)temp_value;
            dp++;
            temp_value = 0;
            shift = 4;
        } else {
            shift -= 4;
        }
        sp++;
    }
    if (shift != 4) {
        shift = 4;
    }
}
