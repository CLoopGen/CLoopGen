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



void loop() {
    for (i = 0; i < row_width; i++) {
        png_uint_16 red, green, blue, gray16;
        png_byte hi, lo;
        // Introduce temporary variables to break immediate RAW dependencies
        png_bytep sp_red_hi = sp++;
        png_bytep sp_red_lo = sp++;
        png_bytep sp_green_hi = sp++;
        png_bytep sp_green_lo = sp++;
        png_bytep sp_blue_hi = sp++;
        png_bytep sp_blue_lo = sp++;

        hi = *sp_red_hi;
        lo = *sp_red_lo;
        red = (png_uint_16)((hi << 8) | lo);
        hi = *sp_green_hi;
        lo = *sp_green_lo;
        green = (png_uint_16)((hi << 8) | lo);
        hi = *sp_blue_hi;
        lo = *sp_blue_lo;
        blue = (png_uint_16)((hi << 8) | lo);

        if (red != green || red != blue)
            rgb_error |= 1;

        // Reorder computation of gray16 to create WAW potential (though not carried)
        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);

        // Break direct dependency on dp update by staging output bytes
        png_byte out_hi = (png_byte)((gray16 >> 8) & 255);
        png_byte out_lo = (png_byte)(gray16 & 255);
        *(dp++) = out_hi;
        *(dp++) = out_lo;

        if (have_alpha != 0) {
            png_bytep sp_alpha_hi = sp++;
            png_bytep sp_alpha_lo = sp++;
            *(dp++) = *sp_alpha_hi;
            *(dp++) = *sp_alpha_lo;
        }
    }
}
