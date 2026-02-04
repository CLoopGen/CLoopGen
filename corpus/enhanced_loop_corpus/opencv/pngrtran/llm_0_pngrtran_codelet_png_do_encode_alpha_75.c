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
    for (png_uint_32 i = 0; i < row_width; ++i) {
        for (int j = 0; j < 1; ++j) { // Artificially nested single-iteration loop
            png_bytep current = row + i * step;
            *current = table[*current];
        }
    }
}
