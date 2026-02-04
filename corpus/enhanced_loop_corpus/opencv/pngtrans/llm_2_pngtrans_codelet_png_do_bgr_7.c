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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access with step 6, reorganize data to be accessed consecutively
    // Assume the original data is grouped as (R,G,B,A) pairs with stride 6, now we process in two separate phases for clarity
    png_bytep r0 = row;
    png_bytep r1 = row + 4;
    png_bytep g0 = row + 1;
    png_bytep g1 = row + 5;

    for (i = 0; i < row_width; i++) {
        png_byte save_r = *r0;
        *r0 = *r1;
        *r1 = save_r;

        png_byte save_g = *g0;
        *g0 = *g1;
        *g1 = save_g;

        r0 += 6;
        r1 += 6;
        g0 += 6;
        g1 += 6;
    }
}
