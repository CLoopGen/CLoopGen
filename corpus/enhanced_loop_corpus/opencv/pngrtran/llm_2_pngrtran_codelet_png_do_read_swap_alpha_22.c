#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward indexing
    png_bytep s = sp - 2 * row_width;
    png_bytep d = dp - 2 * row_width;
    for (i = 0; i < row_width; i++) {
        d[2*i] = s[2*i + 1];
        d[2*i + 1] = s[2*i];
    }
}
