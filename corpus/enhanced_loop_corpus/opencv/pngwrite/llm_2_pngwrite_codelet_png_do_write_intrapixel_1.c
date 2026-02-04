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



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    // This variant assumes row_width is even for simplicity and processes two pixels per iteration
    png_bytep end = row + (row_width * bytes_per_pixel);
    for (i = 0, rp = row; rp + 2 * bytes_per_pixel <= end; i += 2, rp += 2 * bytes_per_pixel) {
        // First pixel in the pair
        *(rp) = (png_byte)(*rp - *(rp + 1));
        *(rp + 2) = (png_byte)(*(rp + 2) - *(rp + 1));
        
        // Second pixel in the pair (if within bounds)
        png_bytep rp_next = rp + bytes_per_pixel;
        if (rp_next + 2 < end) {
            *(rp_next) = (png_byte)(*rp_next - *(rp_next + 1));
            *(rp_next + 2) = (png_byte)(*(rp_next + 2) - *(rp_next + 1));
        }
    }
    // Handle remaining single element if row_width is odd
    if (i < row_width) {
        *(rp) = (png_byte)(*rp - *(rp + 1));
        *(rp + 2) = (png_byte)(*(rp + 2) - *(rp + 1));
    }
}
