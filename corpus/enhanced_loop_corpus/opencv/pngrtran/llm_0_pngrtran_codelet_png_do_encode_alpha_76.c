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
    for (png_uint_32 i = 0; i < row_width; ++i) {
        png_uint_16 v;
        v = table[*(row + 1 + i * step) >> gamma_shift][*(row + i * step)];
        *(row + i * step) = (png_byte)((v >> 8) & 255);
        *(row + i * step + 1) = (png_byte)(v & 255);
    }
}
