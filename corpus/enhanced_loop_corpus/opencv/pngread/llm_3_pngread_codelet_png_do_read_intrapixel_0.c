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
    // Variant 2: Strided memory access - process every second pixel first, then the others
    // Simulates a strided pattern that might occur in image subsampling or multi-pass filters
    int stride = 2;
    // First pass: process pixels at even indices
    for (i = 0; i < row_width; i += stride) {
        rp = row + i * bytes_per_pixel;
        *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
        *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
    }
    // Second pass: process pixels at odd indices (strided access across the row)
    for (i = 1; i < row_width; i += stride) {
        rp = row + i * bytes_per_pixel;
        *(rp) = (png_byte)((256 + *rp + *(rp + 1)) & 255);
        *(rp + 2) = (png_byte)((256 + *(rp + 2) + *(rp + 1)) & 255);
    }
}
