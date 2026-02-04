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
    // Variant 1: Consecutive Memory Access (unrolled by 2 elements for better spatial locality)
    // Assume row_width is even for simplicity; if not, original loop handles remainder
    png_uint_32 limit = row_width - (row_width % 2); // Round down to even
    for (i = 0, rp = row; i < limit; i += 2, rp += 2 * bytes_per_pixel) {
        // Process two pixels consecutively in memory
        png_uint_32 s0_0 = (png_uint_32)(*(rp) << 8) | *(rp + 1);
        png_uint_32 s1_0 = (png_uint_32)(*(rp + 2) << 8) | *(rp + 3);
        png_uint_32 s2_0 = (png_uint_32)(*(rp + 4) << 8) | *(rp + 5);
        png_uint_32 red0 = (png_uint_32)((s0_0 - s1_0) & 65535L);
        png_uint_32 blue0 = (png_uint_32)((s2_0 - s1_0) & 65535L);

        png_uint_32 s0_1 = (png_uint_32)(*(rp + bytes_per_pixel) << 8) | *(rp + bytes_per_pixel + 1);
        png_uint_32 s1_1 = (png_uint_32)(*(rp + bytes_per_pixel + 2) << 8) | *(rp + bytes_per_pixel + 3);
        png_uint_32 s2_1 = (png_uint_32)(*(rp + bytes_per_pixel + 4) << 8) | *(rp + bytes_per_pixel + 5);
        png_uint_32 red1 = (png_uint_32)((s0_1 - s1_1) & 65535L);
        png_uint_32 blue1 = (png_uint_32)((s2_1 - s1_1) & 65535L);

        *(rp) = (png_byte)(red0 >> 8);
        *(rp + 1) = (png_byte)red0;
        *(rp + 4) = (png_byte)(blue0 >> 8);
        *(rp + 5) = (png_byte)blue0;

        *(rp + bytes_per_pixel) = (png_byte)(red1 >> 8);
        *(rp + bytes_per_pixel + 1) = (png_byte)red1;
        *(rp + bytes_per_pixel + 4) = (png_byte)(blue1 >> 8);
        *(rp + bytes_per_pixel + 5) = (png_byte)blue1;
    }
    // Handle remaining pixel if row_width is odd
    if (i < row_width) {
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
