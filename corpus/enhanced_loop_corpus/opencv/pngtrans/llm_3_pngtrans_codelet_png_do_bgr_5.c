#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second pixel (stride of 2 in logical pixel units)
    // Each pixel is 3 bytes, so stride in bytes is 6
    png_uint_32 stride = 2;
    png_uint_32 byte_stride = stride * 3;
    png_uint_32 effective_pixels = (row_width + stride - 1) / stride; // Ceiling division

    for (i = 0, rp = row; i < effective_pixels; i++) {
        png_bytep current_pixel = row + (i * byte_stride);
        png_byte save = current_pixel[0];
        current_pixel[0] = current_pixel[2];
        current_pixel[2] = save;
    }
}
