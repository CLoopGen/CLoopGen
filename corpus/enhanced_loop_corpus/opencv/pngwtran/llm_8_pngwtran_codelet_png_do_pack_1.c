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
    for (i = 0; i < row_width; i += 2) {
        png_byte value1, value2;
        value1 = (png_byte)(*sp & 3);
        v |= (value1 << shift);
        if (shift == 0) {
            shift = 6;
            *dp = (png_byte)v;
            dp++;
            v = 0;
        } else
            shift -= 2;

        sp++;

        if (i + 1 < row_width) {
            value2 = (png_byte)(*sp & 3);
            v |= (value2 << shift);
            if (shift == 0) {
                shift = 6;
                *dp = (png_byte)v;
                dp++;
                v = 0;
            } else
                shift -= 2;
            sp++;
        }
    }
}
