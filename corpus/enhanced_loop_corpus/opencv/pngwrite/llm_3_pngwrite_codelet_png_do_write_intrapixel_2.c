#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern int bytes_per_pixel;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Traversal (stride of bytes_per_pixel, backwards)
    // This variant accesses every 'bytes_per_pixel'-th byte but in reverse order
    // Simulates processing data with strided and reversed access pattern

    // Compute starting point: last valid pixel position
    png_bytep start_rp = row + (row_width - 1) * bytes_per_pixel;
    for (i = 0, rp = start_rp; i < row_width; i++, rp -= bytes_per_pixel) {
        png_uint_32 s0 = (png_uint_32)(*(rp) << 8) | *(rp + 1);
        png_uint_32 s1 = (png_uint_32)(*(rp + 2) << 8) | *(rp + 3);
        png_uint_32 s2 = (png_uint_32)(*(rp + 4) << 8) | *(rp + 5);
        png_uint_32 red = (png_uint_32)((s0 - s1) & 65535L);
        png_uint_32 blue = (png_uint_32)((s2 - s1) & 65535L);

        *(rp) = (png_byte)(red >> 8);
        *(rp + 1) = (png_byte)red;
        *(rp + 4) = (png_byte)(blue >> 8);
        *(rp + 5) = (png_byte)blue;
    }
}
