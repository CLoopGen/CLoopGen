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
    png_byte red, green, blue, alpha;
    png_uint_32 weighted_sum = 0;
    for (i = 0; i < row_width; i++) {
        red   = *(sp++);
        green = *(sp++);
        blue  = *(sp++);
        weighted_sum = (rc * red + gc * green + bc * blue) >> 15;
        *(dp++) = (red == green && red == blue) ? red : (png_byte)(weighted_sum & 0xFF);
        if (red != green || red != blue) {
            rgb_error |= 1;
        }
        if (have_alpha != 0) {
            alpha = *(sp++);
            *(dp++) = alpha;
        }
    }
}
