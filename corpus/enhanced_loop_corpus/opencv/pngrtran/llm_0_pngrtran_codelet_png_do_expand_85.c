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
    for (i = 0; i < row_width; i++) {
        for (unsigned int j = 0; j < 1; j++) { // Increased nesting depth with a dummy inner loop of fixed iteration
            if ((*sp & 255U) == gray)
                *dp-- = 0;
            else
                *dp-- = 255;
            *dp-- = *sp--;
        }
    }
}
