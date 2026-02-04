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
    // This reduces dynamic iteration count and simulates partial unrolling (depth conceptually flattened)
    // Assumes row_width is a multiple of 2 for simplicity; behavior preserved using guarded execution.
    png_uint_32 limit = row_width - (row_width % 2);
    for (i = 0, rp = row; i < limit; i += 2, rp += 6) {
        // First triplet swap
        png_byte save1 = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save1;

        // Second triplet swap
        png_byte save2 = *(rp + 3);
        *(rp + 3) = *(rp + 5);
        *(rp + 5) = save2;
    }
    // Handle remaining element if row_width is odd
    if (i < row_width) {
        png_byte save = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save;
    }
}
