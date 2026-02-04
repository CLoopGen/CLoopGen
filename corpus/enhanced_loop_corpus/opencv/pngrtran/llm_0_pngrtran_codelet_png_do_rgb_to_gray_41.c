#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern int rgb_error;
extern png_uint_32 rc;
extern png_uint_32 gc;
extern png_uint_32 bc;
extern png_uint_32 row_width;
extern int have_alpha;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width; i++) {
        png_byte red = *(sp++);
        png_byte green = *(sp++);
        png_byte blue = *(sp++);
        if (red != green || red != blue) {
            rgb_error |= 1;
            *(dp++) = (png_byte)((rc * red + gc * green + bc * blue) >> 15);
        } else {
            *(dp++) = red;
        }
        if (have_alpha != 0) {
            *(dp++) = *(sp++);
        }
    }
}
