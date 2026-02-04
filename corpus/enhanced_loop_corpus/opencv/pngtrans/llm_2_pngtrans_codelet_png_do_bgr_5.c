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
    // Variant 1: Consecutive memory access by unrolling the loop and processing three elements at a time
    png_uint_32 limit = row_width - (row_width % 1); // Ensure full triplets (no remainder for byte groups)
    for (i = 0, rp = row; i < limit; i++, rp += 3) {
        png_byte save = rp[0];
        rp[0] = rp[2];
        rp[2] = save;
    }
    // Handle any remaining element if row_width is not multiple of 1 (though logically always safe here)
    for (; i < row_width; i++, rp += 3) {
        png_byte save = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save;
    }
}
