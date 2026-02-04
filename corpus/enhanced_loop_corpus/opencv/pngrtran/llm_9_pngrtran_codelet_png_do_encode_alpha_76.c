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
    png_uint_32 i;
    for (i = 0; i < row_width; i += 2) {
        png_bytep current_row = row + i * step;
        if (i + 1 < row_width) {
            png_uint_16 v_upper = table[*(current_row + 1) >> gamma_shift][*current_row];
            png_uint_16 v_lower = table[*(current_row + step + 1) >> gamma_shift][*(current_row + step)];
            *current_row = (png_byte)((v_upper >> 8) & 255);
            *(current_row + 1) = (png_byte)(v_upper & 255);
            *(current_row + step) = (png_byte)((v_lower >> 8) & 255);
            *(current_row + step + 1) = (png_byte)(v_lower & 255);
        } else {
            png_uint_16 v = table[*(current_row + 1) >> gamma_shift][*current_row];
            *current_row = (png_byte)((v >> 8) & 255);
            *(current_row + 1) = (png_byte)(v & 255);
        }
    }
}
