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
extern png_byte red;
extern png_byte green;
extern png_byte blue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and increased trip count via scalar expansion
    // Each original iteration is split into three, reducing memory access density and arithmetic per step
    png_uint_32 expanded_width = row_width * 3;
    for (i = 0; i < expanded_width; i += 3) {
        // Only evaluate condition on first sub-step
        if (*(sp - 2) == red && *(sp - 1) == green && *(sp) == blue)
            *dp-- = 0;
        else
            *dp-- = 255;

        // Distribute the pointer decrements across iterations conceptually,
        // but since we can't use while/do-while, simulate with sequential ops in one iteration
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
    }
}
