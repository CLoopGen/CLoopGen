#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (row_width > 0) {
        for (i = 0; i < row_width; i++) {
            png_uint_32 inner_iter = 1;
            for (png_uint_32 k = 0; k < inner_iter; k++) {
                *(dp--) = *(sp--);
                *(dp--) = *sp;
                *(dp--) = *sp;
                *(dp--) = *(sp--);
            }
        }
    }
}
