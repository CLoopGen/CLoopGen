#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep rp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // Instead of swapping every two bytes with a step of 2 in each iteration,
    // we process two adjacent pairs per iteration for better spatial locality.
    png_uint_32 step = 4;
    png_uint_32 limit = istop * 2;
    for (i = 0; i < limit; i += step) {
        png_bytep current_rp = rp + i;
        // First pair
        png_byte t1 = *current_rp;
        *current_rp = *(current_rp + 1);
        *(current_rp + 1) = t1;
        // Second pair, if within bounds
        if (i + 2 < limit) {
            png_byte t2 = *(current_rp + 2);
            *(current_rp + 2) = *(current_rp + 3);
            *(current_rp + 3) = t2;
        }
    }
}
