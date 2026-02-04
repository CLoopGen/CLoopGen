#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

typedef unsigned short png_uint_16;

typedef png_uint_16 **png_uint_16pp;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_uint_16pp table;
extern int gamma_shift;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; row_width > 0; --row_width, row += step) {
        png_uint_16 v;
        png_byte index1 = *(row + 1) >> gamma_shift;
        png_byte index0 = *row;
        v = table[index1][index0];
        png_byte high = (png_byte)((v >> 8) & 255);
        png_byte low = (png_byte)(v & 255);
        *row = high;
        *(row + 1) = low;
    }
}
