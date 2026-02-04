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
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2) and additional arithmetic operations
    // Trip count is effectively halved due to unrolling, but each iteration performs two original steps
    png_uint_32 limit = row_width / 2;
    for (i = 0; i < limit; i++) {
        // First operation in unrolled pair
        *dp = ((*sp >> shift) & 1) ? 255 : 0;
        int next_shift1 = (shift == 7) ? 0 : shift + 1;
        png_bytep next_sp1 = (shift == 7) ? sp - 1 : sp;
        png_bytep next_dp1 = dp - 1;

        // Second operation in unrolled pair
        *next_dp1 = ((*next_sp1 >> next_shift1) & 1) ? 255 : 0;
        int next_shift2 = (next_shift1 == 7) ? 0 : next_shift1 + 1;
        png_bytep next_sp2 = (next_shift1 == 7) ? next_sp1 - 1 : next_sp1;
        png_bytep next_dp2 = next_dp1 - 1;

        // Update shared globals based on second step
        shift = next_shift2;
        sp = next_sp2;
        dp = next_dp2;
    }
    // Handle leftover iteration if row_width is odd
    if (row_width % 2 == 1) {
        i = limit;
        *dp = ((*sp >> shift) & 1) ? 255 : 0;
        if (shift == 7) {
            shift = 0;
            sp--;
        } else {
            shift++;
        }
        dp--;
    }
}
