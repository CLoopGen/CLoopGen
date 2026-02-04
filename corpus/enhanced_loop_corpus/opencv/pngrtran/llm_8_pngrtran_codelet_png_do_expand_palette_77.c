#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2)
    // This reduces loop trip count by half but increases operations per iteration
    png_uint_32 limit = row_width / 2;
    for (i = 0; i < limit; i++) {
        // First element in unrolled pair
        if ((*sp >> shift) & 1)
            *dp = 1;
        else
            *dp = 0;

        if (shift == 7) {
            shift = 0;
            sp--;
        } else
            shift++;
        dp--;

        // Second element in unrolled pair
        if ((*sp >> shift) & 1)
            *dp = 1;
        else
            *dp = 0;

        if (shift == 7) {
            shift = 0;
            sp--;
        } else
            shift++;
        dp--;
    }

    // Handle remaining element if row_width is odd
    if (row_width % 2 == 1) {
        if ((*sp >> shift) & 1)
            *dp = 1;
        else
            *dp = 0;
        if (shift == 7) {
            shift = 0;
            sp--;
        } else
            shift++;
        dp--;
    }
}
