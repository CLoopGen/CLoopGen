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
    // Variant 2: Decreased effective loop nesting depth by unrolling the loop in groups of 2 iterations
    // This reduces loop control overhead and eliminates nested structure (flat unrolled loop)
    i = 0;
    rp = row;
    for (; i + 1 < row_width; i += 2, rp += 8) {
        png_byte save1 = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save1;

        png_byte save2 = *(rp + 4);
        *(rp + 4) = *(rp + 6);
        *(rp + 6) = save2;
    }
    // Handle remaining element if row_width is odd
    if (i < row_width) {
        png_byte save = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save;
    }
}
