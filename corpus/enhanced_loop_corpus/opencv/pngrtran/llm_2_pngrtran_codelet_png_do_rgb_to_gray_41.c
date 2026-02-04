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
    // Variant 1: Consecutive memory access with pointer arithmetic pre-computed
    png_bytep s_current = sp;
    png_bytep d_current = dp;
    png_uint_32 i;
    for (i = 0; i < row_width; i++) {
        png_byte red = s_current[0];
        png_byte green = s_current[1];
        png_byte blue = s_current[2];
        s_current += 3;
        if (red != green || red != blue) {
            rgb_error |= 1;
            d_current[0] = (png_byte)((rc * red + gc * green + bc * blue) >> 15);
            d_current++;
        } else {
            d_current[0] = red;
            d_current++;
        }
        if (have_alpha) {
            d_current[0] = s_current[0];
            s_current++;
            d_current++;
        }
    }
    sp = s_current;
    dp = d_current;
}
