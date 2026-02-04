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
    // Variant 2: Strided memory access with increasing stride pattern
    // Access elements with a fixed negative stride using offset arithmetic
    for (i = 0; i < row_width; i++) {
        ptrdiff_t idx = i * 4;
        *(dp - idx)     = *(sp - idx);
        *(dp - idx - 1) = *(sp - idx + 1);
        *(dp - idx - 2) = *(sp - idx + 2);
        *(dp - idx - 3) = *(sp - idx + 3);
    }
}
