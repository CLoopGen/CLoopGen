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
    // Variant 2: Reduced computational intensity with combined bit and pointer updates using arithmetic simplification
    // Eliminates conditional branching for shift update using modular arithmetic
    for (i = 0; i < row_width; i++) {
        *dp = ((*sp >> shift) & 1) ? 255 : 0;
        // Use arithmetic instead of conditionals: increment shift and use modulo to wrap at 8
        shift = (shift + 1) & 7;  // Equivalent to shift++ then mod 8, avoids branch
        // Decrement sp only when shift wraps around (i.e., was 7 before increment)
        sp -= (shift == 0) ? 1 : 0;
        dp--;
    }
}
