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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes row_width is even and processes two pixels per iteration to promote sequential access
    png_bytep end = row + (row_width * bytes_per_pixel);
    for (i = 0, rp = row; rp + 2*bytes_per_pixel <= end; i += 2, rp += 2*bytes_per_pixel) {
        // First pixel in pair
        *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
        *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);

        // Second pixel in pair (if within bounds)
        png_bytep rp2 = rp + bytes_per_pixel;
        *(rp2) = (png_byte)((256 + *rp2 + *(rp2 + 1)) & 255);
        *(rp2 + 2) = (png_byte)((256 + *(rp2 + 2) + *(rp2 + 1)) & 255);
    }
    // Handle remaining element if row_width is odd
    if (i < row_width && rp < end) {
        *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
        *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
    }
}
