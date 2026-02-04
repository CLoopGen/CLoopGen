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
    png_uint_32 temp_red, temp_green, temp_blue;
    png_byte gray_val;
    for (i = 0; i < row_width; i++) {
        temp_red   = *(sp++);
        temp_green = *(sp++);
        temp_blue  = *(sp++);
        gray_val = (png_byte)((rc * temp_red + gc * temp_green + bc * temp_blue) >> 15);
        if (temp_red != temp_green || temp_red != temp_blue) {
            rgb_error |= 1;
            *(dp++) = gray_val;
        } else {
            *(dp++) = (png_byte)temp_red;
        }
        if (have_alpha != 0) {
            *(dp++) = *(sp++);
        }
    }
}
