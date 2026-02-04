#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned short png_uint_16;

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
        for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth with a single-iteration loop
            png_uint_16 red, green, blue, gray16;
            png_byte hi, lo;
            hi = *(sp)++;
            lo = *(sp)++;
            red = (png_uint_16)((hi << 8) | (lo));
            hi = *(sp)++;
            lo = *(sp)++;
            green = (png_uint_16)((hi << 8) | (lo));
            hi = *(sp)++;
            lo = *(sp)++;
            blue = (png_uint_16)((hi << 8) | (lo));
            if (red != green || red != blue)
                rgb_error |= 1;
            gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);
            *(dp++) = (png_byte)((gray16 >> 8) & 255);
            *(dp++) = (png_byte)(gray16 & 255);
            if (have_alpha != 0) {
                *(dp++) = *(sp)++;
                *(dp++) = *(sp)++;
            }
        }
    }
}
