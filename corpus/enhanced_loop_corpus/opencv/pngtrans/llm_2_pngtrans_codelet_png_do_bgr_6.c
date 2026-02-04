#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual indexing (unrolled-like pattern)
    png_uint_32 limit = row_width * 4;
    for (i = 0; i < limit; i += 4) {
        png_byte save = row[i];
        row[i] = row[i + 2];
        row[i + 2] = save;
    }
}
