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
    for (i = 0; i < row_width; i += 2) { // Decreased effective depth by processing two elements per iteration, reducing total iterations
        // First element
        if (*(sp - 2) == red && *(sp - 1) == green && *(sp) == blue)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;

        // Second element (unrolled manually without nested loop)
        if (i + 1 < row_width) {
            if (*(sp - 2) == red && *(sp - 1) == green && *(sp) == blue)
                *dp-- = 0;
            else
                *dp-- = 255;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
        }
    }
}
