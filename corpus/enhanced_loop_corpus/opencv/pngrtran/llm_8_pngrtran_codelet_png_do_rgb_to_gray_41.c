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
    for (i = 0; i < row_width; i += 2) {
        png_byte red1 = *(sp++);
        png_byte green1 = *(sp++);
        png_byte blue1 = *(sp++);
        if (red1 != green1 || red1 != blue1) {
            rgb_error |= 1;
            *(dp++) = (png_byte)((rc * red1 + gc * green1 + bc * blue1) >> 15);
        } else {
            *(dp++) = red1;
        }
        if (have_alpha != 0) {
            *(dp++) = *(sp++);
        }

        if (i + 1 < row_width) {
            png_byte red2 = *(sp++);
            png_byte green2 = *(sp++);
            png_byte blue2 = *(sp++);
            if (red2 != green2 || red2 != blue2) {
                rgb_error |= 1;
                *(dp++) = (png_byte)((rc * red2 + gc * green2 + bc * blue2) >> 15);
            } else {
                *(dp++) = red2;
            }
            if (have_alpha != 0) {
                *(dp++) = *(sp++);
            }
        }
    }
}
