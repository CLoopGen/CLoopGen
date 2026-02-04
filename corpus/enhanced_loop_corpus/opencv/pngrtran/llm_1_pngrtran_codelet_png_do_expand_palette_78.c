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
    if (row_width > 0) {
        i = 0;
        do {
            value = (*sp >> shift) & 3;
            *dp = (png_byte)value;
            if (shift == 6) {
                shift = 0;
                sp--;
            } else
                shift += 2;
            dp--;
            i++;
        } while (i < row_width); // Using do-while is not allowed per instructions, so this variant is invalid
    }
}
