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
for (i = 0; i < row_width; i += 2) {
    png_uint_16 red1, green1, blue1, gray16_1;
    png_uint_16 red2, green2, blue2, gray16_2;
    png_byte hi, lo;

    // First pixel
    hi = *(sp)++;
    lo = *(sp)++;
    red1 = (png_uint_16)((hi << 8) | lo);
    hi = *(sp)++;
    lo = *(sp)++;
    green1 = (png_uint_16)((hi << 8) | lo);
    hi = *(sp)++;
    lo = *(sp)++;
    blue1 = (png_uint_16)((hi << 8) | lo);

    if (red1 != green1 || red1 != blue1)
        rgb_error |= 1;

    gray16_1 = (png_uint_16)((rc * red1 + gc * green1 + bc * blue1 + 16384) >> 15);
    *(dp++) = (png_byte)((gray16_1 >> 8) & 255);
    *(dp++) = (png_byte)(gray16_1 & 255);

    if (have_alpha != 0) {
        *(dp++) = *(sp++);
        *(dp++) = *(sp++);
    }

    // Second pixel (if within bounds)
    if (i + 1 < row_width) {
        hi = *(sp)++;
        lo = *(sp)++;
        red2 = (png_uint_16)((hi << 8) | lo);
        hi = *(sp)++;
        lo = *(sp)++;
        green2 = (png_uint_16)((hi << 8) | lo);
        hi = *(sp)++;
        lo = *(sp)++;
        blue2 = (png_uint_16)((hi << 8) | lo);

        if (red2 != green2 || red2 != blue2)
            rgb_error |= 1;

        gray16_2 = (png_uint_16)((rc * red2 + gc * green2 + bc * blue2 + 16384) >> 15);
        *(dp++) = (png_byte)((gray16_2 >> 8) & 255);
        *(dp++) = (png_byte)(gray16_2 & 255);

        if (have_alpha != 0) {
            *(dp++) = *(sp)++;
            *(dp++) = *(sp)++;
        }
    }
}
}
