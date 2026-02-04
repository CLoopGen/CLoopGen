#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep table;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; row_width > 0 && table != NULL; --row_width, row += step) {
        if (*row < 255)
            *row = table[*row];
        else
            *row = 0;
    }
}
