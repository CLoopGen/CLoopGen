#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_shift = shift;
    for (i = 0; i < row_width; i++) {
        int temp_value = (*(sp - (temp_shift == 4 ? 1 : 0))) & 15;
        *dp = (png_byte)temp_value;
        if (temp_shift == 4) {
            temp_shift = 0;
        } else {
            temp_shift += 4;
        }
        dp--;
    }
    shift = temp_shift;
}
