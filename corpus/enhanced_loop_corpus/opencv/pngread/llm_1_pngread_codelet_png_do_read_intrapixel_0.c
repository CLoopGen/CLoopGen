#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern int bytes_per_pixel;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < row_width; i++) {
        png_bytep rp = row + i * bytes_per_pixel;
        for (int j = 0; j < 1; j++) { // Artificially nested single-iteration loop
            *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
            *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
        }
    }
}
