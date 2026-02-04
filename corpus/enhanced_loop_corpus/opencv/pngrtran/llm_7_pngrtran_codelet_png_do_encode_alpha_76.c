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
    png_bytep local_row = row;
    png_uint_32 count = row_width;
    for (; count > 0; --count, local_row += step) {
        png_uint_16 v;
        png_byte temp0 = *local_row;
        png_byte temp1 = *(local_row + 1);
        v = table[temp1 >> gamma_shift][temp0];
        *(local_row + 1) = (png_byte)(v & 255);
        *local_row = (png_byte)((v >> 8) & 255);
    }
    row_width = count;
    row = local_row;
}
