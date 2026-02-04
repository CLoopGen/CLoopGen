#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and increased trip count via scalar expansion
    // Trip count effectively doubled by processing each element twice with different masks
    for (i = 0; i < 2 * row_width; i++) {
        png_byte s_val = *(sp - (i / 2));  // Reuse input byte every two iterations

        if (i % 2 == 0) {
            // First pass: compare with gray using simplified logic (remove redundant &255 on small types)
            *dp-- = (s_val == gray) ? 0 : 255;
        } else {
            // Second pass: store the original value
            *dp-- = s_val;
        }
    }
    // Adjust sp only once per original element
    sp -= row_width;
}
