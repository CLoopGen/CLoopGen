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
// Strided memory access: process every second pixel first, then the others (loop fission-like pattern)
// First pass: even indices
png_uint_32 step = 2;
for (i = 0; i < row_width; i += step) {
    png_uint_16 red, green, blue, gray16;
    png_byte hi, lo;
    // Strided access with fixed offset per component
    hi = sp[(i * 6) + 0];
    lo = sp[(i * 6) + 1];
    red = (png_uint_16)((hi << 8) | lo);
    hi = sp[(i * 6) + 2];
    lo = sp[(i * 6) + 3];
    green = (png_uint_16)((hi << 8) | lo);
    hi = sp[(i * 6) + 4];
    lo = sp[(i * 6) + 5];
    blue = (png_uint_16)((hi << 8) | lo);
    if (red != green || red != blue)
        rgb_error |= 1;
    gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);
    dp[(i * (have_alpha ? 4 : 2)) + 0] = (png_byte)((gray16 >> 8) & 255);
    dp[(i * (have_alpha ? 4 : 2)) + 1] = (png_byte)(gray16 & 255);
    if (have_alpha != 0) {
        dp[(i * 4) + 2] = sp[(i * 6) + 6];
        dp[(i * 4) + 3] = sp[(i * 6) + 7];
    }
}
// Second half: odd indices
for (i = 1; i < row_width; i += step) {
    png_uint_16 red, green, blue, gray16;
    png_byte hi, lo;
    hi = sp[(i * 6) + 0];
    lo = sp[(i * 6) + 1];
    red = (png_uint_16)((hi << 8) | lo);
    hi = sp[(i * 6) + 2];
    lo = sp[(i * 6) + 3];
    green = (png_uint_16)((hi << 8) | lo);
    hi = sp[(i * 6) + 4];
    lo = sp[(i * 6) + 5];
    blue = (png_uint_16)((hi << 8) | lo);
    if (red != green || red != blue)
        rgb_error |= 1;
    gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);
    dp[(i * (have_alpha ? 4 : 2)) + 0] = (png_byte)((gray16 >> 8) & 255);
    dp[(i * (have_alpha ? 4 : 2)) + 1] = (png_byte)(gray16 & 255);
    if (have_alpha != 0) {
        dp[(i * 4) + 2] = sp[(i * 6) + 6];
        dp[(i * 4) + 3] = sp[(i * 6) + 7];
    }
}
}
