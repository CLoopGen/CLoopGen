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
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    png_bytep s = sp;
    png_bytep d = dp;
    for (i = 0; i < row_width; i++) {
        s -= 2;
        d -= 2;
        png_byte temp = *(s + 1);
        *(d) = *(s);
        *(d + 1) = temp;
    }
}
