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
    png_uint_16 red, green, blue, gray16;
    png_byte hi, lo;
    // Consecutive memory access with pointer arithmetic precomputed
    png_bytep src_base = sp + i * 8; // Assuming 2 bytes per RGB and no alpha in base
    hi = src_base[0];
    lo = src_base[1];
    red = (png_uint_16)((hi << 8) | lo);
    hi = src_base[2];
    lo = src_base[3];
    green = (png_uint_16)((hi << 8) | lo);
    hi = src_base[4];
    lo = src_base[5];
    blue = (png_uint_16)((hi << 8) | lo);
    if (red != green || red != blue)
        rgb_error |= 1;
    gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);
    png_bytep dst_base = dp + i * (have_alpha ? 4 : 2);
    dst_base[0] = (png_byte)((gray16 >> 8) & 255);
    dst_base[1] = (png_byte)(gray16 & 255);
    if (have_alpha != 0) {
        dst_base[2] = src_base[6];
        dst_base[3] = src_base[7];
    }
}
}
