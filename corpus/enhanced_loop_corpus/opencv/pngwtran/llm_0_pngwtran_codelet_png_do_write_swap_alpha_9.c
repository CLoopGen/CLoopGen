#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < row_width; i++) {
        png_byte save[2];
        sp = row + (i * 4);
        dp = row + (i * 4);
        save[0] = *(sp++);
        save[1] = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = *(sp++);
        *(dp++) = save[0];
        *(dp++) = save[1];
    }
}
