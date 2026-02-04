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
for (i = 0; i < row_width; i++) {
    *(dp--) = *(sp--);
    *(dp--) = *(sp--);
    if (i != 0) {
        *(dp--) = *sp;
        *(dp--) = *(sp - 1);
        *(dp--) = *sp;
        *(dp--) = *(sp - 1);
    } else {
        *(dp--) = 0;
        *(dp--) = 0;
        *(dp--) = 0;
        *(dp--) = 0;
    }
    *(dp--) = *(sp--);
    *(dp--) = *(sp--);
}
}
