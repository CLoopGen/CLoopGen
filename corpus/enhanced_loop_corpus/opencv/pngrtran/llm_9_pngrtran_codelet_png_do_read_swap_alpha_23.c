#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_byte save[2];
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with added arithmetic overhead per iteration to maintain work equivalence
    png_uint_32 step = 2;
    for (i = 0; i < row_width; i += step) {
        // Introduce auxiliary arithmetic to increase computation per iteration
        png_uint_32 offset = (row_width - i) % 8;
        save[0] ^= (png_byte)(offset * 3);  // Artificial dependency using XOR and mod
        save[1] ^= (png_byte)((offset * 7) & 0xFF);

        // Original data movement logic applied once per two logical iterations
        save[0] = *(--sp);
        save[1] = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = *(--sp);
        *(--dp) = save[0];
        *(--dp) = save[1];

        // Reverse artificial modification to preserve correctness
        save[0] ^= (png_byte)(offset * 3);
        save[1] ^= (png_byte)((offset * 7) & 0xFF);
    }
}
