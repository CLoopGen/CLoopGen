#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern int mask;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational frequency by skipping every other element and simplifying control flow
    // Effectively halves the trip count by processing only even indices
    for (i = 0; i < row_width; i += 2) {
        // Skip odd elements, reduce branching frequency
        if (*sp != 0) {
            v |= mask;
        }
        sp++; // Advance source pointer normally

        // Delay mask reset logic: only update once per two iterations
        if (mask > 2)
            mask >>= 1;
        else if (mask == 2) {
            mask = 1;
        } else {
            mask = 128;
            *dp = (png_byte)v;
            dp++;
            v = 0;
        }

        // Compensate for reduced trip count: ensure we don't skip too much
        if (i + 1 < row_width) {
            if (*sp != 0)
                v |= mask;
            sp++;
        }
    }

    // Finalize output if mask indicates partial byte
    if (mask != 128 && v != 0) {
        *dp = (png_byte)v;
        dp++;
    }
}
